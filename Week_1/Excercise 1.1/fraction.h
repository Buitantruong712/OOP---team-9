#pragma once

#include "support.h"

#define ERROR UINT8_MAX

struct Fraction {
    int a; // numerator
    int b; // denominator
};

// Set and get
Fraction Input(int a, int b);
void Output(Fraction f);
void Getline(std::string type, Fraction f);

// Operator
Fraction operator - (Fraction f);
Fraction operator + (Fraction f, Fraction g);
Fraction operator - (Fraction f, Fraction g);
Fraction operator * (Fraction f, Fraction g);
Fraction operator / (Fraction f, Fraction g);

// Support
Fraction Inverse(Fraction f);
bool CheckError(Fraction f); // If the denominator is zero, return false
Fraction Reduce(Fraction f); // Reduce the fraction. E.g: 3/6 = 1/2, 4/1 = 4
Fraction PositiveDenominator(Fraction f); // E.g: 4/-7 = -4/7
