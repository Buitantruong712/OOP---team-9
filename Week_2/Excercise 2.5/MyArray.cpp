#include "MyArray.h"

void MyArray::Input() {
	do {
		cout << "Input size: ";
		cin >> size;
	} while (size <= 0 && cout << "Invalid value. Please enter again.\n\n");
	
	for (int i = 0; i < size; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void MyArray::Output() {
	for (int i = 0; i < size; i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

unsigned short MyArray::Size() {
	return size;
}

int MyArray::Get(unsigned short pos) {
	return a[pos];
}

bool MyArray::Find(int key) {
	for (int i = 0; i < size; i++)
		if (a[i] == key)
			return 1;
	return 0;
}

void compare_swap(int& a, int& b) {
	if (a > b)
		swap(a, b);
}

void MyArray::sortIncrease() {
	for (int i = size - 1; i > 0; i--)
		compare_swap(a[i - 1], a[i]);
	for (int i = 2; i < size; i++) {
		int v = a[i];
		int j = i;
		for (j; v < a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = v;
	}
}

void MyArray::sortDecrease() {
	for (int i = size - 1; i > 0; i--)
		compare_swap(a[i], a[i - 1]);
	for (int i = 2; i < size; i++) {
		int v = a[i];
		int j = i;
		for (j; v > a[j - 1]; j--)
			a[j] = a[j - 1];
		a[j] = v;
	}
}