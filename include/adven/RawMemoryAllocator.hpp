/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_RAWMEMORYALLOCATOR_HPP
#define DM_ADVEN_RAWMEMORYALLOCATOR_HPP

#include <cstddef>
#include "Log.hpp"
#include "Allocator.hpp"

namespace Adven
{
    class RawMemoryAllocator : public Adven::Allocator
    {
    private:
        const std::size_t MemoryStart;
        const std::size_t MemorySize;
        bool allocated;
    public:
        RawMemoryAllocator(std::size_t memoryStart, std::size_t memorySize);
    public:
        RawMemoryAllocator(RawMemoryAllocator&) = delete;
        RawMemoryAllocator(RawMemoryAllocator&&) = delete;
        RawMemoryAllocator operator=(RawMemoryAllocator) = delete;
        RawMemoryAllocator& operator=(RawMemoryAllocator&) = delete;

        [[nodiscard]] void* Allocate(std::size_t size) override;
        void Deallocate(void* pointer) override;
    };
}

#endif
