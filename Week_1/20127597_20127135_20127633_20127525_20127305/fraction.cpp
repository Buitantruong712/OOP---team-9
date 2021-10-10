#include "fraction.h"

// ~ ~ ~ ~ ~ ~ ~ ~ ~ Set and get ~ ~ ~ ~ ~ ~ ~ ~ ~
Fraction FractionInput() {
    Fraction f;
    cout << "numerator = ";
    cin >> f.a;
    do {
        cout << "denominator = ";
        cin >> f.b;
    } while (!CheckError(f) && cout << "Math ERROR\n");
    f = PositiveDenominator(f);
    return f;
}

void Output(Fraction f) {
    if (!CheckError(f))
        cout << "ERROR";
    else if (f.a == 0)
        cout << 0;
    else if (f.b == 1)
        cout << f.a;
    else {
        f = Reduce(f);
        cout << f.a << "/" << f.b;
    }
    cout << endl;
}

void Getline(string type, Fraction f) {
    cout << type << ": ";
    Output(f);
    putchar('\n');
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ Operator ~ ~ ~ ~ ~ ~ ~ ~ ~
Fraction operator-(Fraction f) {
    return { -1 * f.a, f.b };
}

Fraction operator+(Fraction f, Fraction g) {
    f.a = f.a * g.b + f.b * g.a;
    f.b = f.b * g.b;

    f = Reduce(f);

    return f;
}

Fraction operator-(Fraction f, Fraction g) {
    g = -g;
    f = f + g;
    return f;
}

Fraction operator*(Fraction f, Fraction g) {
    f.a *= g.a;
    f.b *= g.b;

    f = Reduce(f);

    return f;
}

Fraction operator/(Fraction f, Fraction g) {
    g = PositiveDenominator(Inverse(g));

    if (!CheckError(g)) return g;

    f = f * g;
    return f;
}

// ~ ~ ~ ~ ~ ~ ~ ~ ~ Support ~ ~ ~ ~ ~ ~ ~ ~ ~
int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

bool CheckError(Fraction f) {  
    // Check if the fraction is marked as error. The numerator is marked as unique number
    if (f.b == 0) {
        f.a = ERROR;
        return false;
    }
    return (f.a == ERROR ? false : true);
}

Fraction Inverse(Fraction f) {
    swap(f.a, f.b);
    return PositiveDenominator(f);
}

Fraction Reduce(Fraction f) {
    if (f.a == 0) return f;
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