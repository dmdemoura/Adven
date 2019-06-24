/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_ALLOCATOR_HPP
#define DM_ADVEN_ALLOCATOR_HPP

namespace Adven
{
    class Allocator
    {
    public:
        [[nodiscard]] virtual void* Allocate(std::size_t size) = 0;
        virtual void Deallocate(void* pointer) = 0;
        virtual ~Allocator() = default;
    };
}

#endif