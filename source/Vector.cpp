#include "Vector.hpp"

Vector::Vector() : Vector(0,0) {}
Vector::Vector(int x, int y) : x(x), y(y) {}

Vector Vector::operator+=(Vector a)
{
    x += a.x;
    y += a.y;
    return *this;
}
Vector Vector::operator-=(Vector a)
{
    x -= a.x;
    y -= a.y;
    return *this;
}
Vector Vector::operator-()
{
    return {-x, -y};
}
Vector operator+(Vector a, Vector b)
{
    return {a.x + b.x, a.y + b.y};
}
Vector operator-(Vector a, Vector b)
{
    return {a.x - b.x, a.y - b.y};
}
Vector operator*(Vector a, int b)
{
    return {a.x * b, a.y * b};
}
Vector operator*(int a, Vector b)
{
    return b * a;
}
