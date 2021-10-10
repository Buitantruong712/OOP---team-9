#include "complex.h"

//Input, Output function
Complex ComplexInput() {
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

// Calculate module of complex number
float Module(Complex a) { return (float)sqrt(double(a.real) * a.real + double(a.imag) * a.imag); }

//Support check error of division of complex number
bool CheckError(const Complex& a, const Complex& b) {
    return !(b.real == 0 && b.imag == 0);
}

// Define operator for complex number 
Complex operator + (const Complex& a, const Complex& b) {
    return { a.real + b.real, a.imag + b.imag };
}

Complex operator - (const Complex& a, const Complex& b) {
    return { a.real - b.real, a.imag - b.imag };
}

Complex operator * (const Complex& a, const Complex& b) {
    float realPart = a.real * b.real - a.imag * b.imag;
    float imagPart = a.real * b.imag + b.real * a.imag;
    return { realPart, imagPart };
}

Complex operator / (const Complex& a, const Complex& b) {
    float denominator = b.real * b.real + b.imag * b.imag;
    float  realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    float imagPart = (a.imag * b.real - b.imag * a.real) / denominator;
    return { realPart, imagPart };
}