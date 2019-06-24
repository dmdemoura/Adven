/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_MATH_HPP
#define DM_ADVEN_MATH_HPP

namespace Adven
{
    namespace Math
    {
        constexpr int Power(int base, int exp)
        {
            int power = 1;
            for (int i = 0; i < exp; i++)
            {
                power *= base;
            }
            return power;
        }
        constexpr int Power2(int exp)
        {
            int power = 1;
            for (int i = 0; i < exp; i++)
            {
                power = power << 1;
            }
            return power;
        }
        constexpr int Log2(int number)
        {
            int exp = 0;
            int power = 1;
            for (exp = 0; power < number; exp++)
            {
                power = power << 1;
            }
            return exp;
        }
        template <typename T>
        constexpr T RoundToNextPowerOf2(T number)
        {
            number--;
            for (int i = 1; i < (sizeof(T) >> 1); i = i << 1)
            {
                number |= number >> i;
            }
            number++;
            return number;
        }
    }
}

#endif