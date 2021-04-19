#ifndef RATIONAL_H
#define RATIONAL_H


class Rational
{
    int a, b;
public:
    Rational();
    Rational(int a, int b);

    Rational simplify();
    static int gcd(int a, int b);
    int numerator();
    int denominator();
    bool isNaN();

    operator double() const { return double(a) / b; }
    operator bool() const { return (b == 0 || a != 0); }

    friend bool operator== (const Rational &r1, const Rational &r2);
    friend Rational operator+(const Rational &r1, const Rational &r2);
    friend Rational operator-(const Rational &r1, const Rational &r2);
    friend Rational operator*(const Rational &r1, const Rational &r2);
    friend Rational operator/(const Rational &r1, const Rational &r2);

};

#endif // RATIONAL_H
