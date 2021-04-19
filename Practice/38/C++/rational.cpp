#include "rational.h"
#include <iostream>
#include <math.h>

int Rational::gcd(int a, int b) {
    a = abs(a); b = abs(b);
    if (a == 0 || b == 0) {
        return std::max(a, b);
    }
    while (a != b) {
        if (a > b)
            a = a-b;
        else
            b = b-a;
    }
    return a;
}

Rational Rational::simplify() {
    int gcd_value = gcd(a, b);
    if (gcd_value == 0) {
        if (a == 0 && b == 0)
            return Rational(0, 0);
        if (a > b) {
            return Rational(0, 1);
        } else {
            int sign = (signbit(a) xor signbit(b))? -1 : 1;
            return Rational(sign*1, 0);
        }
    }
    return Rational(int(a / gcd_value), int(b / gcd_value));
}

int Rational::numerator() {
    return a;
}

int Rational::denominator() {
    return b;
}

bool Rational::isNaN() {
    return (a == 0 && b == 0);
}

bool operator== (const Rational &r1, const Rational &r2) {
    Rational r1copy = r1;
    Rational r2copy = r2;
    r1copy = r1copy.simplify();
    r2copy = r2copy.simplify();
    if ( r1copy.isNaN() || r2copy.isNaN() )
        return false;
    int sign1 = (signbit(r1copy.a) xor signbit(r1copy.b))? -1 : 1;
    int sign2 = (signbit(r2copy.a) xor signbit(r2copy.b))? -1 : 1;
    if (r1copy.a == 0) sign1 = 1;
    if (r2copy.a == 0) sign2 = 1;
    r1copy.a = abs(r1copy.a); r1copy.b = abs(r1copy.b);
    r2copy.a = abs(r2copy.a); r2copy.b = abs(r2copy.b);
    return (r1copy.a == r2copy.a && r1copy.b ==r2copy.b && sign1 == sign2);
}

Rational operator+(const Rational &r1, const Rational &r2) {
    Rational copyr1 = r1;
    Rational copyr2 = r2;
    if (copyr1.isNaN() || copyr2.isNaN())
        return Rational(0, 0);
    if (r1.b == r2.b)
        return Rational(r1.a+r2.a, r1.b);
    Rational sum( r1.a * r2.b + r2.a * r1.b,
                  r1.b * r2.b );
    return sum.simplify();
}

Rational operator-(const Rational &r1, const Rational &r2) {
    Rational copyr1 = r1;
    Rational copyr2 = r2;
    if (copyr1.isNaN() || copyr2.isNaN())
        return Rational(0, 0);
    if (r1.b == r2.b)
        return Rational(r1.a-r2.a, r1.b);
    Rational sub( r1.a * r2.b - r2.a * r1.b,
                  r1.b * r2.b );
    return sub.simplify();
}

Rational operator*(const Rational &r1, const Rational &r2) {
    Rational mul( abs(r1.a * r2.a),
                  abs(r1.b * r2.b) );
    int sign = (signbit(r1.a) xor signbit(r1.b) xor signbit(r2.a) xor signbit(r2.b))? -1 : 1;
    if (mul.a == 0)
        mul.b = sign*mul.b;
    else
        mul.a = sign*mul.a;
    return mul.simplify();
}

Rational operator/(const Rational &r1, const Rational &r2) {
    Rational div( abs(r1.a * r2.b),
                  abs(r1.b * r2.a) );
    int sign = (signbit(r1.a) xor signbit(r1.b) xor signbit(r2.a) xor signbit(r2.b))? -1 : 1;
    if (div.a == 0)
        div.b = sign*div.b;
    else
        div.a = sign*div.a;
    return div.simplify();
}

Rational::Rational()
    : a(0)
    , b(1){}

Rational::Rational(int a, int b)
    : a(a)
    , b(b){}
