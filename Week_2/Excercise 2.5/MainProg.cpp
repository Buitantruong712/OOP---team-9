#include "MyArray.h"

int main() {
	MyArray a;
	cout << "INPUT ARRAY: " << endl;
	a.Input();

	while (1) {
		short type;
		cout << "\nEnter your choice:\n0.Exit\n1.Output array\n2.Get size of array\n3.Get item at another position\n4.Find another item in array\n5.Sort increasingly\n6.Sort decreasingly\n";
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
			} while ((pos <= 0 || pos >= a.Size()) && cout << "Invalid value. Please enter again!\n\n");
			cout << "The item at position " << pos << " is: " << a.Get(pos);
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
			cout << "Invalid type. Please enter again!." << endl << endl;
			break;
		}
	}
	return 0;
}
