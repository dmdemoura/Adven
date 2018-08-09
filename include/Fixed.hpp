#ifndef DM_FIXED
#define DM_FIXED

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

#endif