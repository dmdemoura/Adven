#ifndef DM_VECTOR
#define DM_VECTOR


class Vector {
public:
    int x;
    int y;
    Vector();
    Vector(int x, int y);
    Vector operator+=(Vector a);
    Vector operator-=(Vector a);
    Vector operator-();
};

Vector operator+(Vector a, Vector b);
Vector operator-(Vector a, Vector b);
Vector operator*(Vector a, int b);
Vector operator*(int a, Vector b);
bool operator==(Vector a, Vector b);
bool operator!=(Vector a, Vector b);

#endif