/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_BUDDYALLOCATOR_HPP
#define DM_ADVEN_BUDDYALLOCATOR_HPP

#include <advenCore/HwUtils.hpp>
#include "Allocator.hpp"
#include "RawMemoryAllocator.hpp"

namespace Adven
{
    class BuddyAllocator : public Adven::Allocator
    {
    private:
        struct FreeBlock
        {
            FreeBlock* previousBlock;
            FreeBlock* nextBlock;
            std::size_t blockSize;
        };
    private:
        const std::size_t MemorySize;
        const std::size_t MinBlockSize;
        const std::size_t MaxBlockSize;
        Adven::Allocator& allocator;
        void* memory;
        FreeBlock* firstBlock;
    private:
        /**
         * Splits a free block into two, updating the next block.
         * @param block Block to split.
         * @returns The new block split from the first.
         */
        FreeBlock* SplitBlock(FreeBlock* block);
         /**
         * Tries to find a preexisting block of size equal to blockSize.
         * @param blockSize Size of the block to search for.
         * @see AllocSpace()
         * @return A free block, if possible, otherwise a nullptr.
         */
        FreeBlock* FindBlock(std::size_t blockSize);
    public:
        /**
         *  Marks the entire memory as free, initializing all free blocks.
         *  Should only be called by Singleton.
         *  @see Adven::Singleton
         */
        BuddyAllocator(std::size_t memorySize, std::size_t minBlockSize, std::size_t maxBlockSize, Adven::Allocator& allocator);
        ~BuddyAllocator() override;
        BuddyAllocator(BuddyAllocator&) = delete;
        BuddyAllocator(BuddyAllocator&&) = delete;
        BuddyAllocator operator=(BuddyAllocator) = delete;
        BuddyAllocator& operator=(BuddyAllocator&) = delete;

        /**
         * Tries to find or create a block of size equal to blockSize.
         * @param blockSize Size of the block to be returned.
         * @see FindBlock()
         * @returns A free block, if possible, otherwise a nullptr.
         */
        [[nodiscard]] void* Allocate(std::size_t blockSize) override;

        void Deallocate(void* pointer) override;
    };

}

#endif
