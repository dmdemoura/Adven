/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_TILEMAPS_LAYER_HPP
#define DM_ADVEN_TILEMAPS_LAYER_HPP

#include <array>
#include "Chunk.hpp"

namespace Adven::Tilemaps
{
    template <int width, int height>
    class Layer
    {
    public:
        std::array<std::array<Chunk, height>, width> chunks;
    public:
        AdvenCore::ScreenEntry& GetScreenEntry(AdvenCore::Vector position)
        {
            AdvenCore::Vector chunkIndex = position >> Chunk::chunkSizeInPowerOf2;
            AdvenCore::Vector chunkPosition = position - (chunkIndex << Chunk::chunkSizeInPowerOf2);

            return chunks[chunkIndex.x][chunkIndex.y].screenEntries[chunkPosition.x][chunkPosition.y];
        }
    };
}

#endif