#include "Array.h"

int main() {
	// Test constructor, operator [], operator =
	Array a(10, 99);
	cout << "Array a:\n";
	for (int i = 0; i < a.Size(); i++)
		cout << a[i] << " ";
	cout << endl;
	
	cout << "\nArray b:\n";
	Array b(5, 8);
	for (int i = 0; i < b.Size(); i++)
		cout << b[i] << " ";
	cout << endl;

	cout << "\nArray a := Array b\nArray a\n";
	a = b;
	for (int i = 0; i < a.Size(); i++)
		cout << a[i] << " ";

	Array c(b);
	cout << "\nArray c(b):\n";
	for (int i = 0; i < c.Size(); i++)
		cout << c[i] << " ";
	cout << endl;

	cout << "\nChange some elements of array c by cin >> c[i]:\n";
	cout << "Input c[0]: "; cin >> c[0];
	cout << "Input c[4]: "; cin >> c[4];
	cout << "After changing:\n";
	for (int i = 0; i < c.Size(); i++)
		cout << c[i] << " ";
	cout << endl;
	
	// Test type-casting
	cout << "\nTest type-casting operator:\n";

	int* ptr = (int*)a;
	cout << "ptr := (int*)a, *ptr = " << *ptr << endl;

	ptr = (int*)c;
	cout << "ptr := (int*)c, *ptr = " << *ptr << endl;

	ptr = (int*)c + 5;
	cout << "ptr := (int*)c + 4, *ptr = " << *ptr << endl;
	
	// End
	return 0;
}