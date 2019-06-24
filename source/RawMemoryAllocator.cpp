/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "RawMemoryAllocator.hpp"

using namespace Adven;

RawMemoryAllocator::RawMemoryAllocator(std::size_t memoryStart, std::size_t memorySize)
    : allocated(false), MemoryStart(memoryStart), MemorySize(memorySize) {}

[[nodiscard]] void* RawMemoryAllocator::Allocate(std::size_t size)
{
    if (size > MemorySize || allocated)
    {
        Log::Debug << "Raw Bad Alloc size:" << size << " MemorySize " << MemorySize << " allocated" << allocated << std::endl;
        throw std::bad_alloc();
    }
//    Log::Debug << "Raw Allocator Allocate Sucesss" << std::endl;

    allocated = true;

    return reinterpret_cast<void*>(MemoryStart);
}

void RawMemoryAllocator::Deallocate(void* pointer)
{
    if (pointer != reinterpret_cast<void*>(MemoryStart))
    {
        throw std::invalid_argument("pointer should be equal to MemoryStart");
    }

    allocated = false;
}