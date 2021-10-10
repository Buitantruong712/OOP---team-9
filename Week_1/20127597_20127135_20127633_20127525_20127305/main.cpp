#include "complex.h"
#include "fraction.h"

int main() {
    int choose;
    Complex a, b;
    Fraction c, d;
    while (1) {
        cout << "1.Complex number\n2.Fraction\n0.Exit\nYour choose: ";
        cin >> choose;
        if (choose == 1)
            while (1) {
                cout << "\nComplex number "
                    "calculation\n1.Module\n2.Addition\n3.Substraction\n4."
                    "Multiplication\n5."
                    "Division\n0.Back\nYour choose: ";

                cin >> choose;
                if (!choose)
                    break;
                else if (choose == 1) {
                    a = ComplexInput();
                    cout << "\n|" << a.real << " + " << a.imag << "i| = ";
                    cout << Module(a);
                    cout << endl << endl;
                }
                else if (choose > 1 && choose < 6) {
                    cout << "\nFirst fraction\n";
                    a = ComplexInput();
                    cout << "\nSecond fraction\n";
                    b = ComplexInput();
                    cout << endl;

                    if (choose == 2) {
                        Output(a);
                        cout << " + ";
                        Output(b);
                        cout << " = ";
                        Output(a + b);
                        cout << endl << endl;
                    }
                    else if (choose == 3) {
                        cout << "(";
                        Output(a);
                        cout << ") - ";
                        cout << "(";
                        Output(b);
                        cout << ") = ";
                        Output(a - b);
                        cout << endl << endl;
                    }
                    else if (choose == 4) {
                        cout << "(";
                        Output(a);
                        cout << ") x ";
                        cout << "(";
                        Output(b);
                        cout << ") = ";
                        Output(a * b);
                        cout << endl << endl;
                    }
                    else {
                        if (b.real == 0 && b.imag == 0)
                            cout << "Math ERROR\n";
                        else {
                            cout << "(";
                            Output(a);
                            cout << ") / ";
                            cout << "(";
                            Output(b);
                            cout << ") = ";
                            Output(a / b);
                            cout << endl << endl;
                        }
                    }
                }
                else
                    cout << "\nInvalid choose\n\n";
            }
        else if (choose == 2)
            while (1) {
                cout << "\nFraction "
                    "Calculation\n1.Addition\n2.Substraction\n3."
                    "Multiplication\n4.Division\n0.Back\nYour choose: ";

                cin >> choose;
                if (choose > 0 && choose < 5) {
                    cout << "\nFirst fraction\n";
                    c = FractionInput();
                    cout << "\nSecond fracion\n";
                    d = FractionInput();
                    cout << endl;

                    if (choose == 1) {
                        Output(c + d);
                    }
                    else if (choose == 2) {
                        Output(c - d);
                    }
                    else if (choose == 3) {
                        Output(c * d);
                    }
                    else if (choose == 4) {
                        if (!CheckError(Inverse(d)))
                            cout << "Math ERROR\n";
                        else
                            Output(c / d);
                    }
                }
                else
                    cout << "\nInvalid choose\n\n";
            }
        else if (!choose)
            break;
        else
            cout << "Invalid choose\n\n";
    }
    return 0;
}