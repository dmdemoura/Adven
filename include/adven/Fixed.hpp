#ifndef DM_ADVEN_FIXED_HPP
#define DM_ADVEN_FIXED_HPP

namespace Adven
{
    class Fixed
    {
    private:
        int fixed;
        char pointPosition;
    private:
        Fixed(int fixed, char pointPosition);
    public:
        Fixed();
        friend Fixed operator+(Fixed a, Fixed b);
        friend Fixed operator-(Fixed a, Fixed b);
        friend Fixed operator*(Fixed a, Fixed b);
        friend Fixed operator/(Fixed a, Fixed b);
        friend Fixed operator+(Fixed a, int b);
        friend Fixed operator-(Fixed a, int b);
        friend Fixed operator*(Fixed a, int b);
        friend Fixed operator/(Fixed a, int b);
        friend Fixed operator+(int a, Fixed b);
        friend Fixed operator-(int a, Fixed b);
        friend Fixed operator*(int a, Fixed b);
        friend Fixed operator/(int a, Fixed b);
    };
}

#endif