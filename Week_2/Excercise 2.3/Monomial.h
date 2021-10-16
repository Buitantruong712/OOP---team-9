#pragma once
#ifndef _MONOMIAL_H_
#define _MONOMIAL_H_

#include<iostream>
using namespace std;

class Monomial {
private:
	float coefficient, powerNumber;
public:
	Monomial();
	Monomial(float, float);

	friend istream& operator>>(istream&, Monomial&);
	friend ostream& operator<<(ostream&, const Monomial&);

	float getCoefficient();
	void setCoefficient(float);
	float getPowerNumber();
	void setPowerNumber(float);

	bool checkTheSamePower(Monomial);

	Monomial operator+(Monomial);
	Monomial operator-(Monomial);
	Monomial operator*(Monomial);
	Monomial operator/(Monomial);

	Monomial Derivative();
	void anti_Derivative();

	~Monomial();
};

#endif // !_MONOMIAL_H_
