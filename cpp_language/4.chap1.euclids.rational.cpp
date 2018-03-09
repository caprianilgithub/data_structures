#include "4.chap1.euclids.rational.h"

Rational::Rational(int numerator, int denominator)
{
    this->numerator  = numerator;
    this->denominator= denominator;
}

void Rational::reduce()
{
    int a, b, rem, sign;
    
    if(numerator == 0)
    {
        denominator = 1;
    }
    
    sign = 1;
    
    if(numerator < 0 && denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    if(numerator < 0)
    {
        denominator = -denominator;
        sign = -1;
    }
    
    cout << "sign = " << sign << " numerator = " << numerator << " denominator = " << denominator << endl;
    
    if(numerator > denominator)
    {
        cout << "numerator " << numerator << " is > denominator " << denominator << endl;
        a = numerator;
        b = denominator;
    }
    else{
        
        cout << "numerator " << numerator << " is < denominator " << denominator << endl;
        
        a = denominator;
        b = numerator;
        
        cout << "Swapping a = " << numerator << " b = " << denominator << endl;
        
    }
    
    rem = 0;
    
    while(b !=0)
    {
        rem = a %b;
        cout << "a=" << a << " b=" << b << " rem=" << rem << endl;
        a = b;
        b = rem;
        cout << "a=" << a << " b=" << b << " rem=" << rem << endl;
    }
    
    numerator = sign * numerator/a;
    denominator = denominator/a;    
}

Rational Rational::add(Rational r)
{}


Rational Rational::multiply(Rational r)
{}


Rational Rational::divide(Rational r)
{}


int Rational::equal(Rational r)
{}


void Rational::print()
{
    cout << "----numerator is " << numerator << " denominator is " << denominator << endl;
}


int main()
{
    Rational r(14, 8);
    r.reduce();
    r.print();
 
    return(0);
}
