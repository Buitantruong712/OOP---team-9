#include "SortAlgorithm.h"

template <class T>
SortAlgorithm<T>* SortAlgorithm<T>:: _algorithm = NULL;

template <class T>
SortAlgorithm<T>::SortAlgorithm() {
	currentAlgorithm = InsertionSort;
}


template <class T>
SortAlgorithm<T>* SortAlgorithm<T>::getObject(void (*pAlg)(T[], int)) {
	if (_algorithm == NULL) {
		_algorithm = new SortAlgorithm();
	}
	if (pAlg != NULL) {
		_algorithm->currentAlgorithm = pAlg;
	}
	return _algorithm;
}


template <class T>
void SortAlgorithm<T>::SelectionSort(T a[], int n) {
	int min;
	for (int i = 0; i < n - 1;i++) {
		min = i;
		for (int j = i + 1;j < n;j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			T temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}

template <class T>
void SortAlgorithm<T>::InsertionSort(T a[], int n) {
	int pos;
	T x;
	for (int i = 0; i < n;i++) {
		x = a[i];
		for (pos = i;(pos > 0 && a[pos - 1] > x);pos--) {
			a[pos] = a[pos - 1];
		}
		a[pos] = x;
	}
}


template <class T>
void SortAlgorithm<T>::InterchangeSort(T a[], int n) {
	for (int i = 0; i < n - 1;i++) {
		for (int j = i + 1;j < n;j++) {
			if (a[j] < a[i]) {
				T temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


template <class T>
void SortAlgorithm<T>::Sort(T a[], int n) {
	if (currentAlgorithm != NULL) {
		currentAlgorithm(a, n);
	}
}
