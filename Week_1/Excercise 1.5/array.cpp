#include "array.h"

Array input() {
	Array result;
	while (1) {
		cout << "Input size of array: ";
		cin >> result.size;
		if (result.size <= 0)
			cout << "Invalid value. Please enter again." << endl << endl;
		else break;
	}
	for (int i = 0; i < result.size; i++) {
		cout << "a[" << i << "] = ";
		cin >> result.a[i];
	}
	return result;
}
void output(Array a) {
	int n = getSize(a);
	for (int i = 0; i < n; i++)
		cout << getItem(a, i) << "\t";
	cout << endl;
}
int getSize(Array a) {
	return a.size;
}
int getItem(Array a, int pos) {
	return a.a[pos];
}
bool findItem(Array a, int item) {
	int n = getSize(a);
	for (int i = 0; i < n; i++) {
		if (getItem(a, i) == item)
			return true;
	}
	return false;
}
void compare_swap(int& a, int& b) {
	if (a > b)
		swap(a, b);
}
void sortIncrease(Array &a) {
	int n = getSize(a);
	for (int i = n - 1; i > 0; i--)
		compare_swap(a.a[i - 1], a.a[i]);
	for (int i = 2; i < n; i++) {
		int v = getItem(a, i);
		int j = i;
		for (j; v < getItem(a, j - 1); j--)
			a.a[j] = a.a[j - 1];
		a.a[j] = v;
	}
}
void sortDecrease(Array &a) {
	int n = getSize(a);
	for (int i = n - 1; i > 0; i--)
		compare_swap(a.a[i], a.a[i - 1]);
	for (int i = 2; i < n; i++) {
		int v = getItem(a, i);
		int j = i;
		for (j; v > getItem(a, j - 1); j--)
			a.a[j] = a.a[j - 1];
		a.a[j] = v;
	}
}