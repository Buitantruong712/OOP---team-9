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
	// print the real number, except for the case where real number = 0 and imagine number <> 0
	// e.g. 0 + ai = ai
	if (a.real != 0 || a.imag == 0)
	    cout << a.real;
	    
    if (a.imag == 0) return;
    
    if (a.imag > 0) {
    	if (a.real != 0)
	    	cout << " + ";
    	if (a.imag != 1)
    		cout << a.imag;
    	cout << "i";
	}
	
	else {
		cout << " - ";
		if (a.imag != -1)
    		cout << -a.imag;
    	cout << "i";
	}
}

// Calculate module of complex number
float Module(Complex a) { return (float)sqrt(double(a.real) * a.real + double(a.imag) * a.imag); }

//Support check error of division of complex number
bool CheckError(const Complex a) {
    return !(a.real == 0 && a.imag == 0);
}   

// Define operator for complex number 
Complex operator + (const Complex a, const Complex b) {
    return { a.real + b.real, a.imag + b.imag };
}

Complex operator - (const Complex a, const Complex b) {
    return { a.real - b.real, a.imag - b.imag };
}

Complex operator * (const Complex a, const Complex b) {
    float realPart = a.real * b.real - a.imag * b.imag;
    float imagPart = a.real * b.imag + b.real * a.imag;
    return { realPart, imagPart };
}

Complex operator / (const Complex a, const Complex b) {
    float denominator = b.real * b.real + b.imag * b.imag;
    float  realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    float imagPart = (a.imag * b.real - b.imag * a.real) / denominator;
    return { realPart, imagPart };
}
