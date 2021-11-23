#include "Array.h"
#include "HocSinh.h"

int main() {
	///////////////////////// EX1 //////////////////////////////////
	int temp;
	cout << "Ex1: \n";
	// Default constructor
	cout << "1) Default constructor\n";
	Array a;
	cout << "Array a: " << a << endl << endl;

	// Constructor with given size
	cout << "2) Constructor with given size\n";
	cout << "Array b(x). Input x: ";
	cin >> temp;
	Array b(temp);
	cout << "Array b(" << temp << "): " << b << endl << endl;

	// Constructor from int[] with given size
	cout << "3) Constructor from int[] with given size\n";
	cout << "Array c(arr[], x)\n";
	cout << "Input arr[]:\n";
	int sizeOfTempArr = 0;
	int* tempArr = inputArray(sizeOfTempArr);
	Array c(tempArr, sizeOfTempArr);
	cout << "Array c(arr[], " << sizeOfTempArr << "): " << c << endl << endl;

	// Constructor from another Array object
	cout << "4) Constructor from int[] with given size\n";
	Array d(c);
	cout << "Array d(c): " << d << endl << endl;

	// Operator =
	a = b;
	cout << "5) Array a := Array b\n=> Array a: " << a << endl << endl;

	// Operator []
	cout << "6) Operator []\n";
	cout << "Change an element of array c by cin >> c[i]:\n";
	do {
		cout << "Input i: ";
		cin >> temp;
	} while (temp < 0 || temp >= c.Size() && cout << "Invalid value. Please enter again\n");
	cout << "c[" << temp << "] = ";
	cin >> c[temp];
	cout << "After changing:\n";
	cout << c << endl << endl;

	// Test type-casting
	cout << "7) Test type-casting\n";

	int* ptr = (int*)a;
	cout << "ptr := (int*)a, *ptr = " << *ptr << endl;

	ptr = (int*)c;
	cout << "ptr := (int*)c, *ptr = " << *ptr << endl;

	///////////////////////// EX2 //////////////////////////////////
	cout << "\nEx2:\n";
	// Default constructor
	cout << "1) Default constructor\n";
	HocSinh hs1;
	cout << "Hoc sinh hs1:\n" << hs1 << endl << endl;

	// operator >> 
	cout << "Input hoc sinh hs1:\n";
	cin.ignore();
	cin >> hs1;
	cout << "\nHoc sinh hs1:\n" << hs1 << endl << endl;

	// Constructor from another HocSinh object
	cout << "2) Constructor from another HocSinh object HocSinh hs2(hs1)\n";
	HocSinh hs2(hs1);
	cout << "Hoc sinh hs2:\n" << hs2 << endl << endl;

	// Operator =
	cout << "3)  Operator =\n";
	cout << "Input hs1:\n"; cin >> hs1;
	hs2 = hs1;
	cout << "\nhs2 := hs1, hs1:\n" << hs1 << "\nhs2:\n" << hs2 << endl << endl;

	// Comparison operator GPA
	HocSinh hs1, hs2;
	cout << "4) Test comparison operator\n";
	cout << "Input 2 HocSinh:\n";
	cout << "\nhs1:\n"; cin >> hs1;
	cout << "\nhs2:\n"; cin >> hs2;
	cout << "HocSinh1 > HocSinh2: " << (hs1 > hs2 ? "True" : "False") << endl;
	cout << "HocSinh1 < HocSinh2: " << (hs1 < hs2 ? "True" : "False") << endl;
	cout << "HocSinh1 == HocSinh2: " << (hs1 == hs2 ? "True" : "False") << endl;
	cout << "HocSinh1 >= HocSinh2: " << (hs1 >= hs2 ? "True" : "False") << endl;
	cout << "HocSinh1 <= HocSinh2: " << (hs1 <= hs2 ? "True" : "False") << endl;
	cout << "HocSinh1 != HocSinh2: " << (hs1 != hs2 ? "True" : "False") << endl << endl;

	// type - casting (char*)
	cout << "5) Test type - casting\n";
	char* ptr2 = (char*)hs1;
	cout << "char* ptr = char*(hs1), *ptr: " << ptr2 << endl;
	ptr2 = (char*)hs2;
	cout << "char* ptr = char*(hs2), *ptr: " << ptr2 << endl;

	return 0;
}
