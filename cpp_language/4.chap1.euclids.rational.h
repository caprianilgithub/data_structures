#include <iostream>

using namespace std;

class Rational
{
    int numerator;
    int denominator;
    
public:
    Rational(int numerator, int denominator);
    Rational(const Rational& r);        /* Copy Constructor */
    Rational& operator=(Rational &r);   /* Assignment operator= */
    void reduce();
    Rational add(Rational r);
    Rational multiply(Rational r);
    Rational divide(Rational r);
    int equal(Rational r);
    void print();
};
