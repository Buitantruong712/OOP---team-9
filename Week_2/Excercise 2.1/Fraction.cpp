#include "Fraction.h"

// Math function
int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

// Input, Output
istream& operator>>(istream& is, Fraction& F) {
    cout << "Numerator = ";
    is >> F.numerator;
    do {
        cout << "Denominator = ";
        is >> F.denominator;
        if (F.denominator) break;
    } while (1 && cout << "Math ERROR\n");

    return is;
}

ostream& operator<<(ostream& os, Fraction& F) {
    Fraction tmp = F.Reduce();
    if (tmp.denominator == -1) {
        tmp.numerator *= -1;
        tmp.denominator *= -1;
    }
    os << tmp.numerator;
    if (tmp.numerator != 0) os << "/" << tmp.denominator;
    cout << endl;

    return os;
}

// Get, set method
void Fraction::setDenominator(int de) { denominator = de; }

void Fraction::setNumerator(int nu) { numerator = nu; }

int Fraction::getDenominator() { return denominator; }

int Fraction::getNumerator() { return numerator; }

// Support function
Fraction Fraction::Reduce() {
    int common = GCD(numerator, denominator);
    Fraction tmp;
    tmp.setNumerator(numerator / common);
    tmp.setDenominator(denominator / common);

    return tmp;
}

Fraction Fraction::Inverse() {
    Fraction tmp;
    tmp.setNumerator(denominator);
    tmp.setDenominator(numerator);

    return tmp;
}

// Calculation
Fraction Fraction::operator+(const Fraction& F) {
    Fraction tmp;
    tmp.setNumerator(numerator * F.denominator + F.numerator * denominator);
    tmp.setDenominator(denominator * F.denominator);

    return tmp.Reduce();
}

Fraction Fraction::operator-(const Fraction& F) {
    Fraction tmp;
    tmp.setNumerator(numerator * F.denominator - F.numerator * denominator);
    tmp.setDenominator(denominator * F.denominator);

    return tmp.Reduce();
}

Fraction Fraction::operator*(const Fraction& F) {
    Fraction tmp;
    tmp.setNumerator(numerator * F.numerator);
    tmp.setDenominator(denominator * F.denominator);

    return tmp.Reduce();
}

// Be careful
// Division should be carried out only if checking
bool Check(const Fraction& F) { return F.numerator; }

Fraction Fraction::operator/(const Fraction& F) {
    Fraction tmp;
    tmp.setNumerator(numerator * F.denominator);
    tmp.setDenominator(denominator * F.numerator);

    return tmp.Reduce();
}