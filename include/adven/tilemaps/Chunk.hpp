/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_TILEMAPS_CHUNK_HPP
#define DM_ADVEN_TILEMAPS_CHUNK_HPP

#include <array>
#include <advenCore/Vector.hpp>
#include <advenCore/ScreenEntry.hpp>

namespace Adven::Tilemaps
{
    class Chunk
    {
    public:
        static constexpr int chunkSize = 32;
        static constexpr int chunkSizeInPowerOf2 = 5;
        std::array<std::array<AdvenCore::ScreenEntry, chunkSize>, chunkSize> screenEntries;
    };
}

#endif