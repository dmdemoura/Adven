/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_LOG_HPP
#define DM_ADVEN_LOG_HPP

#include <ostream>

namespace Adven
{
    namespace Log
    {
        extern std::ostream Debug;
        extern std::ostream Warning;
        extern std::ostream Error;
    };
}

#endif