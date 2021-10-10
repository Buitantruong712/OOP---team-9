#pragma once

#include <iostream>

using namespace std;
#define ERROR INT32_MIN

struct Fraction {
    int a; // numerator
    int b; // denominator
};

// Set and get
Fraction FractionInput();
void Output(Fraction f);
void Getline(string type, Fraction f);

// Operator
Fraction operator - (Fraction f);
Fraction operator + (Fraction f, Fraction g);
Fraction operator - (Fraction f, Fraction g);
Fraction operator * (Fraction f, Fraction g);
Fraction operator / (Fraction f, Fraction g);

// Support
int GCD(int a, int b);
Fraction Inverse(Fraction f);
bool CheckError(Fraction f); // If the denominator is zero, return false
Fraction Reduce(Fraction f); // Reduce the fraction. E.g: 3/6 = 1/2, 4/1 = 4
Fraction PositiveDenominator(Fraction f); // E.g: 4/-7 = -4/7