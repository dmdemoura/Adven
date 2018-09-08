#include "Math.hpp"

int Math::Power(int base, int exp)
{
    int power = 1;
    for (int i = 0; i < exp; i++)
    {
        power *= base;
    }
    return power;
}