#include <iostream>
#include <math.h>
#include <string>

using namespace std;
#define ERROR INT32_MIN

struct Complex {
    float real, imag;
};

//Check error when make complex division
bool CheckError(const Complex& a, const Complex& b);

//Input, Output function
Complex ComplexInput();
void Output(Complex a);

// Calculate module of complex number
float Module(Complex a);

// Define operator for complex number 
Complex operator + (const Complex& a, const Complex& b);
Complex operator - (const Complex& a, const Complex& b);
Complex operator * (const Complex& a, const Complex& b);
Complex operator / (const Complex& a, const Complex& b);