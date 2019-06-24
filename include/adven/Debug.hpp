/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_DEBUG_HPP
#define DM_ADVEN_DEBUG_HPP

#include <string>

namespace Adven
{
    class Debug
    {
    public:
        static void Log(std::string message);
        static void Warning(std::string message);
        static void Error(std::string message);
    };
}

#endif