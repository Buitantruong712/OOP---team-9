#include "Array.h"

int main() {
	// Test constructor
	cout << "1) Test constructor\n";
	Array a(5);
	cout << "Array a ({0}, 5):\n";
	for (int i = 0; i < a.Size(); i++)
		cout << a[i] << " ";
	cout << endl;

	int _b[] = { 8, 7, 6, 7, 8, 7, 6, 7 };
	Array b(_b, 8);
	cout << "\nArray b ({8, 7, 6, 7, 8, 7, 6, 7}, 8):\n";
	for (int i = 0; i < b.Size(); i++)
		cout << b[i] << " ";
	cout << endl;

	cout << "\nArray a := Array b\n=> Array a:\n";
	a = b;
	for (int i = 0; i < a.Size(); i++)
		cout << a[i] << " ";

	Array c(b);
	cout << "\nArray c(b):\n";
	for (int i = 0; i < c.Size(); i++)
		cout << c[i] << " ";
	cout << endl;

	// Test istream and ostream
	cout << "\n2) Test istream and ostream\n";
	Array d;
	cin >> d;
	cout << d;

	// Test operator []
	cout << "\n3) Test operator []\n";
	cout << "\nChange some elements of array c by cin >> c[i]:\n";
	cout << "Input c[0]: "; cin >> c[0];
	cout << "Input c[4]: "; cin >> c[4];
	cout << "After changing:\n";
	for (int i = 0; i < c.Size(); i++)
		cout << c[i] << " ";
	cout << endl;

	// Test type-casting and operator =
	cout << "\n4) Test type-casting and operator = []\n";

	int* ptr = (int*)a;
	cout << "ptr := (int*)a, *ptr = " << *ptr << endl;

	ptr = (int*)c;
	cout << "ptr := (int*)c, *ptr = " << *ptr << endl;

	ptr = (int*)c + 5;
	cout << "ptr := (int*)c + 4, *ptr = " << *ptr << endl;

	// End
	return 0;
}
