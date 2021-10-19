#include "MyArray.h"
#include "Fraction.h"

int main() {
	short type;
	while (1) {
		cout << "\nEnter your choice:\n0.Exit\n1.Fraction problem\n2.Array problem\n";
		cin >> type;

		if (type == 0)
			break;
		// FRACTION PROBLEM
		if (type == 1) {
			Fraction f1, f2, result;
			cout << "\nINPUT FRACTION 1:\n";
			cin >> f1;
			cout << "Fraction 1 = " << f1 << endl;
			cout << "\nINPUT FRACTION 2:\n";
			cin >> f2;
			cout << "Fraction 2 = " << f2 << endl;
			while (1) {
				cout << "\nEnter your choice:\n0.Back\n1.Addition\n2.Substraction\n3.Multiplication"
					"\n4.Division\n5.Inverse\n";
				cin >> type;

				if (type == 0) break;

				switch (type)
				{
				case 1:
					result = f1 + f2;
					cout << f1 << " + " << f2 << " = " << result << endl;
					break;
				case 2:
					result = f1 - f2;
					cout << f1 << " - " << f2 << " = " << result << endl;
					break;
				case 3:
					result = f1 * f2;
					cout << f1 << " * " << f2 << " = " << result << endl;
					break;
				case 4:
					if (f2.getNumerator() == 0) {
						cout << "Can't division.\n\n";
						break;
					}
					result = f1 / f2;
					cout << f1 << " : " << f2 << " = " << result << endl;
					break;

				case 5:
					if (f1.getNumerator() == 0)
						cout << f1 << " can't inverse." << endl;
					else {
						result = f1.Inverse();
						cout << f1 << " inversed: " << result << endl;
					}
					if (f2.getNumerator() == 0)
						cout << f2 << " can't inverse." << endl;
					else {
						result = f2.Inverse();
						cout << f2 << " inversed: " << result << endl;
					}
					break;
				default:
					cout << "Invalid type. Please enter again!\n\n";
					break;
				}
			}
		}
		// ARRAY PROBLEM
		else if (type == 2) {
			MyArray a;
			cout << "INPUT ARRAY: " << endl;
			a.Input();

			while (1) {
				cout << "\nEnter your choice:\n0.Back\n1.Output array\n2.Get size of array\n3.Get item at another position"
					"\n4.Find another item in array\n5.Sort increasingly\n6.Sort decreasingly\n";
				cin >> type;

				if (type == 0)
					break;
				switch (type) {
				case 1:
					cout << "ARRAY:\t ";
					a.Output();
					break;
				case 2:
					cout << "Size of array: " << a.Size() << endl;
					break;
				case 3:
					short pos;
					do {
						cout << "Input position you want to get: ";
						cin >> pos;
					} while ((pos < 0 || pos >= a.Size()) && cout << "Invalid value. Please enter again!\n\n");
					cout << "The item at position " << pos << " is: " << a.Get(pos) << endl;
					break;
				case 4:
					int key;
					cout << "Input item you want to find: ";
					cin >> key;
					if (a.Find(key))
						cout << key << " was found in array." << endl;
					else
						cout << key << " wasn't found in array." << endl;
					break;
				case 5:
					a.sortIncrease();
					a.Output();
					break;
				case 6:
					a.sortDecrease();
					a.Output();
					break;
				default:
					cout << "Invalid type. Please enter again!\n\n";
					break;
				}
			}
		}
		else cout << "Invalid type. Please enter again\n\n";
	}
	return 0;
}
