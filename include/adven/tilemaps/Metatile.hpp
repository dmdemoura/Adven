/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_TILEMAPS_METATILE_HPP
#define DM_ADVEN_TILEMAPS_METATILE_HPP

#include <array>

namespace Adven::Tilemaps
{
    template <int width, int height>
    class Metatile
    {
    private:
        std::array<std::array<ScreenEntry, height>, width> tileIDs;
    };
}

#endif