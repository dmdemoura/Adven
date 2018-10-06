/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Math.hpp"

using namespace Adven;

int Math::Power(int base, int exp)
{
    int power = 1;
    for (int i = 0; i < exp; i++)
    {
        power *= base;
    }
    return power;
}