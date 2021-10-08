#include <iostream>
#include <math.h>

using namespace std;

struct Complex {
    double real, imag;
};

Complex Input() {
    Complex a;
    cout << "Real part = ";
    cin >> a.real;
    cout << "Imaginary part = ";
    cin >> a.imag;
    return a;
}

void Output(Complex a) {
    cout << a.real;
    if (a.imag == 0) return;
    else if (a.imag > 0) cout << " + " << a.imag << "i";
    else cout << " - " << -1 * a.imag << "i";
}

double Module(Complex a) { return sqrt(a.real * a.real + a.imag * a.imag); }

Complex Addition(Complex a, Complex b) {
    return { a.real + b.real, a.imag + b.imag };
}

Complex Substraction(Complex a, Complex b) {
    return { a.real - b.real, a.imag - b.imag };
}

Complex Multiplication(Complex a, Complex b) {
    float realPart = a.real * b.real - a.imag * b.imag;
    float imagPart = a.real * b.imag + b.real * a.imag;
    return { realPart, imagPart };
}

Complex Division(Complex a, Complex b) {
    double denominator = b.real * b.real + b.imag * b.imag;
    double realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    double imagPart = (a.imag * b.real - b.imag * a.real) / denominator;
    return { realPart, imagPart };
}

void Process() {
    int choose;
    Complex a, b;
    while (1) {
        cout << "1.Module\n2.Addition\n3.Substraction\n4.Multiplication\n5."
            "Division\n0.Exit\nYour choose: ";
        cin >> choose;
        if (!choose)
            break;
        else if (choose == 1) {
            a = Input();
            cout << "\n|" << a.real << " + " << a.imag << "i| = ";
            cout << Module(a);
            cout << endl << endl;
        }
        else if (choose > 1 && choose < 6) {
            cout << endl;
            a = Input();
            b = Input();
            cout << endl;
            if (choose == 2) {
                Output(a); cout << " + "; Output(b); cout << " = ";
                Output(Addition(a, b));
                cout << endl << endl;
            }
            else if (choose == 3) {
                cout << "("; Output(a); cout << ") - "; cout << "("; Output(b); cout << ") = ";
                Output(Substraction(a, b));
                cout << endl << endl;
            }
            else if (choose == 4) {
                cout << "("; Output(a); cout << ") x "; cout << "("; Output(b); cout << ") = ";
                Output(Multiplication(a, b));
                cout << endl << endl;
            }
            else {
                cout << "("; Output(a); cout << ") / "; cout << "("; Output(b); cout << ") = ";
                Output(Division(a, b));
                cout << endl << endl;
            }
        }
        else
            cout << "\nInvalid choose\n\n";
    }
}

int main() {
    Process();
    return 0;
}