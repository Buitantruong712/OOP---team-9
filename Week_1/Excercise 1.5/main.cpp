#include "array.h"

int main() {
	Array a;
	cout << "INPUT ARRAY: " << endl;
	a = input();
	
	while (1) {
		unsigned short type;
		cout << "\nEnter your choice:\n0.Exit\n1.Output array\n2.Get size of array\n3.Get item at another position\n4.Find another item in array\n5.Sort increasingly\n6.Sort decreasingly\n";
		cin >> type;
		if (type == 0)
			break;
		switch (type) {
		case 1:
			cout << "ARRAY: ";
			output(a);
			break;
		case 2:
			cout << "Size of array: " << getSize(a) << endl;
			break;
		case 3:
			unsigned short pos;
			cout << "Input position you want to get: ";
			cin >> pos;
			cout << "The item at position " << pos << " is: " << getItem(a, pos);
			break;
		case 4:
			int key;
			cout << "Input item you want to find: ";
			cin >> key;
			if (findItem(a, key))
				cout << key << " was found in array." << endl;
			else
				cout << key << " wasn't found in array." << endl;
			break;
		case 5:
			sortIncrease(a);
			output(a);
			break;
		case 6:
			sortDecrease(a);
			output(a);
			break;
		default:
			cout << "Invalid type. Please enter again!." << endl << endl;
			break;
		}
	}
	return 0;
}