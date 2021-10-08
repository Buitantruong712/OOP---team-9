#include "fraction.h"


// ~ ~ ~ ~ ~ ~ ~ ~ ~ Set and get ~ ~ ~ ~ ~ ~ ~ ~ ~ 
Fraction Input(int a, int b) {
    Fraction f;
    f.a = a;
    f.b = b;

    if (!CheckError(f))
        return f;

    f = PositiveDenominator(f);
    return f;
}

void Output(Fraction f) {
    if (!CheckError(f))
        std::cout << "ERROR";
    else if (f.a == 0)
        std::cout << 0;
    else if (f.b == 1)
        std::cout << f.a;
    else
        std::cout << f.a << '/' << f.b;
}

void Getline(std::string type, Fraction f) {
    std::cout << type << ": ";
    Output(f);
    putchar('\n');
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ Operator ~ ~ ~ ~ ~ ~ ~ ~ ~ 
Fraction operator - (Fraction f) {
    if (!CheckError(f))
        return f;

    f.a /= -1;
    return f;
}

Fraction operator + (Fraction f, Fraction g) {
    if (!CheckError(f))
        return f;
    if (!CheckError(g))
        return g;

    f.a = f.a * g.b + f.b * g.a;
    f.b = f.b * g.b;

    f = Reduce(f);

    return f;
}

Fraction operator - (Fraction f, Fraction g) {
    if (!CheckError(f))
        return f;
    if (!CheckError(g))
        return g;

    g = -g;
    f = f + g;
    return f;
}

Fraction operator * (Fraction f, Fraction g) {
    if (!CheckError(f))
        return f;
    if (!CheckError(g))
        return g;

    f.a *= g.a;
    f.b *= g.b;

    f = Reduce(f);

    return f;
}

Fraction operator / (Fraction f, Fraction g) {
    if (!CheckError(f))
        return f;

    g = PositiveDenominator(Inverse(g));

    if (!CheckError(g))
        return g;

    f = f * g;
    return f;
}


// ~ ~ ~ ~ ~ ~ ~ ~ ~ Support ~ ~ ~ ~ ~ ~ ~ ~ ~ 
bool CheckError(Fraction f) { // Check if the fraction is marked as error. The numerator is marked as unique number
    if (f.b == 0) {
        f.a = ERROR;
        return false;
    }
    return (f.a == ERROR ? false : true);
}

Fraction Inverse(Fraction f) {
    if (!CheckError(f))
        return f;

    int inverse = f.a;
    f.a = f.b;
    f.b = inverse;
    f = PositiveDenominator(f);
    return f;
}

Fraction Reduce(Fraction f) {
    if (f.a == 0)
        return f;
    int gcd = GCD(abs(f.a), abs(f.b));

    if (gcd != 1) {
        f.a /= gcd;
        f.b /= gcd;
    }
    return f;
}

Fraction PositiveDenominator(Fraction f) {
    if (f.b < 0) {
        f.a /= -1;
        f.b /= -1;
    }
    return f;
}