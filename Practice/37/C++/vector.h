#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"

class Vector
{
    Point begin, end;
public:
    Vector();
    Vector(Point end);
    Vector(Point begin,  Point end);

    double length();

    friend bool operator== (const Vector &v1, const Vector &v2);
    friend Vector operator- (const Vector &v);
    friend Vector operator+(const Vector &v1, const Vector &v2);
    friend Vector operator-(const Vector &v1, const Vector &v2);
    friend Vector operator*(const Vector &v, const double &x);
    friend Vector operator*(const double &x, const Vector &v);
    friend double operator*(const Vector &v1, const Vector &v2);
};

#endif // VECTOR_H
