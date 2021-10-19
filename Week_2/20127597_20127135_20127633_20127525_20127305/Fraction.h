#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
private:
    int denominator;
    int numerator;
public:
    // Input, Output
    friend istream& operator >> (istream&, Fraction&);
    friend ostream& operator << (ostream&, Fraction&);

    // Get method
    int getDenominator();
    int getNumerator();

    // Set method
    void setDenominator(int);
    void setNumerator(int);

    // Reduce, Inverse
    Fraction Inverse();
    Fraction Reduce();

    // Calculation
    Fraction operator + (const Fraction&);
    Fraction operator - (const Fraction&);
    Fraction operator * (const Fraction&);
    Fraction operator / (const Fraction&);
};

// support for Reduce() function
int GCD(int a, int b);
#endif

