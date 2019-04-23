/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <adven/Log.hpp>
#include <adven/Exceptions.hpp>
#include <adven/Math.hpp>
#include "BuddyAllocator.hpp"

using namespace Adven;

BuddyAllocator::BuddyAllocator(std::size_t memorySize, std::size_t minBlockSize, std::size_t maxBlockSize, Adven::Allocator& allocator)
    : MemorySize(memorySize), MinBlockSize(minBlockSize), MaxBlockSize(maxBlockSize), allocator(allocator)
{
//    Log::Debug << "CStart" << std::endl;
    memory = allocator.Allocate(memorySize);
//    Log::Debug << "Memory Size: " << memorySize << std::endl;

    firstBlock = reinterpret_cast<FreeBlock*>(memory);

    FreeBlock* lastBlock = nullptr;
    for (int i = 0; i * MaxBlockSize < MemorySize; i++)
    {
        FreeBlock* currentBlock = AdvenCore::HwUtils::OffsetPointer(firstBlock, MaxBlockSize * i);

        currentBlock->blockSize = MaxBlockSize;
        currentBlock->previousBlock = lastBlock;
        currentBlock->nextBlock = nullptr;

        if (lastBlock)
            lastBlock->nextBlock = currentBlock;

        lastBlock = currentBlock;
    }
//    Log::Debug << "CEnd" << std::endl;
}

BuddyAllocator::FreeBlock* BuddyAllocator::SplitBlock(BuddyAllocator::FreeBlock* block)
{
    //Halves the blockSize
    block->blockSize = block->blockSize >> 1;

    //Creates the other half
    FreeBlock* newBlock = AdvenCore::HwUtils::OffsetPointer(block, block->blockSize);

    newBlock->blockSize = block->blockSize;
    newBlock->previousBlock = block;
    newBlock->nextBlock = block->nextBlock;

    block->nextBlock = newBlock;

    return newBlock;
}

typename BuddyAllocator::FreeBlock* BuddyAllocator::FindBlock(std::size_t blockSize)
{
    FreeBlock* currentBlock = firstBlock;

    while(currentBlock && currentBlock->blockSize != blockSize)
    {
//        Log::Debug << "Find Find" << std::endl;
        currentBlock = currentBlock->nextBlock;
    }

    return currentBlock;
}

void* BuddyAllocator::Allocate(std::size_t blockSize)
{
//    Log::Debug << "AStart" << std::endl;
    blockSize = Math::RoundToNextPowerOf2(blockSize);
    FreeBlock* block = nullptr;

    std::size_t increasingBlockSize = blockSize;

//    Log::Debug << "Max Allocation Block Size" << MaxBlockSize << std::endl;
    while (block == nullptr && increasingBlockSize <= MaxBlockSize)
    {
//        Log::Debug << "Block size: " << increasingBlockSize << std::endl;
        block = FindBlock(increasingBlockSize);
        increasingBlockSize *= 2;
    }

    //Memory is either full or too fragmented.
    if (block == nullptr)
    {
        Log::Debug << "BuddyAllocator bad alloc" << std::endl;
        throw std::bad_alloc();
    }

    while (block->blockSize != blockSize)
    {
//        Log::Debug << "Split Split" << std::endl;
        SplitBlock(block);
    }

    //Disconnect block from the list.
    //No need to deallocate, because the list uses the unallocated memory.
    block->previousBlock->nextBlock = block->nextBlock;
    block->nextBlock->previousBlock = block->previousBlock;

    if (block == firstBlock)
        firstBlock = block->nextBlock;

//    Log::Debug << "AEnd" << std::endl;
    return block;
}

void BuddyAllocator::Deallocate(void* pointer)
{
    //TODO: Implement deallocation
    throw Adven::NotImplementedException();
}

BuddyAllocator::~BuddyAllocator()
{
    allocator.Deallocate(memory);
}
