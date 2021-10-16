#include"Monomial.h"

int main() {
	Monomial mono1, mono2;
	// Input and output
	cout << "Enter mononial 1\n";
	cin >> mono1;
	cout << "\nEnter mononial 2\n";
	cin >> mono2;
	cout << "\nMonomial 1: " << mono1;
	cout << "\nMonomial 2: " << mono2;

	//	Set and get
	/*cout << "\nGet coefficient of monomial 1: " << mono1.getCoefficient();
	cout << "\nGet power number of monomial 1: " << mono1.getPowerNumber();
	mono1.setPowerNumber(2);
	mono1.setPowerNumber(0);*/

	// Calculation
	if (mono1.checkTheSamePower(mono2)) {
		cout << "\n\nAddition: " << mono1 + mono2;
		cout << "\nSubtraction: " << mono1 - mono2;
		cout << "\nMultiplication: " << mono1 * mono2;
		if (mono2.getCoefficient() == 0) cout << "\nCan't find division!\n";
		else	cout << "\nDivision: " << mono1 / mono2;
	}
	else cout << "\n\n2 monomials don't have the same power!\n";

	// Derivative and anti-derivative
	cout << "\n\nDerivative of monomial 1: " << mono1.Derivative();
	cout << "\nAnti-derivative of monomial 1: ";
	mono1.anti_Derivative();
	cout << "\n\nDerivative of monomial 2: " << mono2.Derivative();
	cout << "\nAnti-derivative of monomial 2: ";
	mono2.anti_Derivative();

	cout << endl;
}