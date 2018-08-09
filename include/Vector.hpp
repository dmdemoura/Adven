#ifndef DM_VECTOR
#define DM_VECTOR


class Vector {
public:
    int x;
    int y;
    Vector();
    Vector(int x, int y);
    Vector& operator+=(Vector& a);
};

Vector operator+(Vector& a, Vector& b);

#endif