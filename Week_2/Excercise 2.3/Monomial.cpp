#include"Monomial.h"

Monomial::Monomial() {}
Monomial::Monomial(float a, float b) {
	coefficient = a;
	powerNumber = b;
}

float Monomial::getCoefficient() { return coefficient; }
void Monomial::setCoefficient(float a) { coefficient = a; }

float Monomial::getPowerNumber() { return powerNumber; }
void Monomial::setPowerNumber(float a) { powerNumber = a; }


istream& operator>>(istream& is, Monomial& dt) {
	cout << "Enter coefficient: ";
	is >> dt.coefficient;
	cout << "Enter power number: ";
	is >> dt.powerNumber;
	return is;
}

ostream& operator<<(ostream& os, const Monomial& dt) {
	if (dt.coefficient == 0) os << 0;
	else if (dt.coefficient == 1) {
		if (dt.powerNumber == 0) os << 1;
		else if (dt.powerNumber == 1) os << "x";
		else os << "x^" << dt.powerNumber;
	}
	else if (dt.coefficient == -1) {
		if (dt.powerNumber == 0) os << -1;
		else if (dt.powerNumber == 1) os << "-x";
		else os << "-x^" << dt.powerNumber;
	}
	else {
		if (dt.powerNumber == 0) os << dt.coefficient;
		else if (dt.powerNumber == 1) os << dt.coefficient << "x";
		else os << dt.coefficient << "x^" << dt.powerNumber;
	}
	return os;
}

bool Monomial::checkTheSamePower(Monomial dt) {
	if (powerNumber == dt.powerNumber) return true;
	return false;
}

Monomial Monomial::operator+(Monomial dt) {
	Monomial kq(coefficient + dt.coefficient, powerNumber);
	return kq;
}

Monomial Monomial::operator-(Monomial dt) {
	Monomial kq(coefficient - dt.coefficient, powerNumber);
	return kq;
}

Monomial Monomial::operator*(Monomial dt) {
	Monomial kq(coefficient * dt.coefficient, powerNumber + dt.powerNumber);
	return kq;
}

Monomial Monomial::operator/(Monomial dt) {
	Monomial kq(coefficient / dt.coefficient, 0);
	return kq;
}

Monomial Monomial::Derivative() {
	Monomial kq;
	if (coefficient == 0) kq.coefficient = 0;
	else {
		if (powerNumber == 0) kq.coefficient = 0;
		else if (powerNumber == 1) {
			kq.coefficient = coefficient;
			kq.powerNumber = 0;
		}
		else {
			kq.coefficient = coefficient * powerNumber;
			kq.powerNumber = powerNumber - 1;
		}
	}
	return kq;
}

void Monomial::anti_Derivative() {
	if (coefficient == 0) cout << "C (C belong to R)";
	else {
		if (powerNumber >= 0) {
			if (powerNumber == 0) cout << coefficient << "x + C";
			else cout << coefficient / (powerNumber + 1) << "x^" << powerNumber + 1 << " + C";
		}
		else {
			if (powerNumber == -1) cout << coefficient << "ln(|x|) + C";
			else cout << coefficient / (powerNumber + 1) << "x^" << powerNumber + 1 << " + C";
		}
	}
}


Monomial::~Monomial() {}