#pragma once
#include <iostream>

using namespace std;

class Fraction {
private:
    int denominator;
    int numerator;

    // Check error before division
public:
    // Input, Output
    friend istream& operator >> (istream&, Fraction&);
    friend ostream& operator << (ostream&, Fraction&);

    // Set, Get method
    void setDenominator(int);
    void setNumerator (int);
    int getDenominator();
    int getNumerator();

    // Support fraction
    Fraction Inverse();
    Fraction Reduce();

    // Calculation
    Fraction operator + (const Fraction&);
    Fraction operator - (const Fraction&);
    Fraction operator * (const Fraction&);
    friend bool Check(const Fraction&);
    Fraction operator / (const Fraction&);
};