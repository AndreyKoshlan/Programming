#include "vector.h"
#include <math.h>

bool operator== (const Vector &v1, const Vector &v2) {
    Vector copyv1 = v1;
    Vector copyv2 = v2;
    if (copyv1.length() == copyv2.length()) {
        double cosine = (v1*v2)/(copyv1.length()*copyv2.length());
        if (cosine - 1 < pow(10, -10)) {
            return true;
        }
    }
    return false;
}

Vector operator- (const Vector &v) {
    Vector vcopy = v;
    std::swap(vcopy.begin, vcopy.end);
    return vcopy;
}

Vector operator+(const Vector &v1, const Vector &v2) {
    return Vector(v1.begin + v2.begin, v1.end + v2.end);
}

Vector operator-(const Vector &v1, const Vector &v2) {
    return Vector(v1.begin - v2.begin, v1.end - v2.end);
}

Vector operator*(const Vector &v, const double &x) {
    return Vector(v.begin * x, v.end * x);
}

Vector operator*(const double &x, const Vector &v) {
    return v*x;
}

double operator*(const Vector &v1, const Vector &v2) {
    Point p1 = v1.end-v1.begin;
    Point p2 = v2.end-v2.begin;
    return p1.get_x()*p2.get_x() + p1.get_y()*p2.get_y();
}

double Vector::length() {
    Point p = end-begin;
    return hypot(p.get_x(), p.get_y());
}

Vector::Vector()
    : begin(Point(0, 0, Cartesian))
    , end(Point(1, 0, Cartesian)){}

Vector::Vector(Point end)
    : begin(Point(0, 0, Cartesian))
    , end(end){}

Vector::Vector(Point begin, Point end)
    : begin(begin)
    , end(end){}
