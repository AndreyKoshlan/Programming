#include "rational.h"
#include <iostream>
#include <math.h>

int Rational::gcd(int a, int b) {
    a = std::abs(a); b = std::abs(b);
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
    if (gcd_value == 0) { //если gcd равен 0, то это NaN
        return Rational(0, 0);
    }
    return Rational(int(a / gcd_value), int(b / gcd_value));
}

Rational Rational::abs() {
    return Rational(std::abs(a), std::abs(b));
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

int Rational::sign() {
    if (a != 0)
        return (signbit(a) xor signbit(b))? -1 : 1;
    else
        return 1;
}

bool operator== (const Rational &r1, const Rational &r2) {
    Rational r1copy = r1;
    Rational r2copy = r2;

    /* NaN, с точки зрения математики - это неопределённое число, то есть любое.
     * Поэтому он не равен ни чему, даже самому себе */
    if ( r1copy.isNaN() || r2copy.isNaN() )
        return false;

    /* Сравниваем значения по модулю и проверяем равенство знаков */
    if (r1copy.sign() == r2copy.sign()) {
        r1copy = r1copy.simplify().abs();
        r2copy = r2copy.simplify().abs();
        return (r1copy.a == r2copy.a && r1copy.b ==r2copy.b);
    } else {
        return false;
    }
}

Rational operator+(const Rational &r1, const Rational &r2) {
    Rational r1copy = r1;
    Rational r2copy = r2;
    if (r1copy.isNaN() || r2copy.isNaN())
        return Rational(0, 0);
    if (r1.b == r2.b)
        return Rational(r1.a+r2.a, r1.b).simplify();
    else
        return Rational(r1.a * r2.b + r2.a * r1.b,
                        r1.b * r2.b).simplify();
}

Rational operator-(const Rational &r1, const Rational &r2) {
    return r1 + Rational(-r2.a, r2.b);
}

Rational operator*(const Rational &r1, const Rational &r2) {
    Rational mul( abs(r1.a * r2.a),
                  abs(r1.b * r2.b) );
    int sign = Rational(r1.a, r1.b).sign() * Rational(r2.a, r2.b).sign();
    mul.a = sign*mul.a;
    return mul.simplify();
}

Rational operator/(const Rational &r1, const Rational &r2) {
    return r1 * Rational(r2.b, r2.a);
}

Rational::Rational()
    : a(0)
    , b(1){}

Rational::Rational(int a, int b)
    : a(a)
    , b(b){}
