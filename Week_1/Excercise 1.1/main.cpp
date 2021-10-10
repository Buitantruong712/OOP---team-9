#include <iostream>
#include "fraction.h"

int main() {
    Fraction a, b, c;
    a = FractionInput();
    b = FractionInput();

    Getline("a", a);
    Getline("b", b);
    std::cout << "\nc = a ... b\n\n";
    // Sum
    c = a + b;
    Getline("Sum         ", c);
    // Subtract
    c = b - a;
    Getline("Subtract b-a", c);
    // Multiply
    c = a * b;
    Getline("Multiply    ", c);
    // Divide
    c = b / a;
    Getline("Divide b/a  ", c);
    c = a / b;
    Getline("Divide a/b  ", c);
    c = Inverse(c);
    Getline("Invert c    ", c);
}
