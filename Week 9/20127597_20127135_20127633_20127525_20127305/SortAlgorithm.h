#ifndef _SORTALGORITHM_H_
#define _SORTALGORITHM_H_

#include <iostream>
#include <string>
using namespace std;

template <class T>
class SortAlgorithm {
private:
	static SortAlgorithm* _algorithm;
	void (*currentAlgorithm)(T a[], int);
	SortAlgorithm();
public:
	static SortAlgorithm* getObject(void (*pAlg)(T[], int) = NULL);
	static void SelectionSort(T[], int);
	static void InsertionSort(T[], int);
	static void InterchangeSort(T[], int);
	void Sort(T[], int);
};


template <class T>
SortAlgorithm<T>* SortAlgorithm<T>::_algorithm = NULL;

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




class STUDENT {
	string name;
	double grade;
public:
	STUDENT();
	STUDENT(string, double);
	STUDENT(const STUDENT&);
	STUDENT(STUDENT*);
	double get_Grade();
	bool operator<(const STUDENT&);
	bool operator>(const STUDENT&);
	friend istream& operator>>(istream&, STUDENT&);
	friend ostream& operator<<(ostream&, STUDENT);

	~STUDENT();
};

STUDENT::STUDENT() {
	name = " ";
	grade = 0;
}
STUDENT::STUDENT(string _name, double _grade) {
	if (_grade < 0)
		_grade = 0;
	name = _name;
	grade = _grade;
}

STUDENT::STUDENT(const STUDENT& s) {
	name = s.name;
	grade = s.grade;
}


STUDENT::STUDENT(STUDENT* s) {
	name = s->name;
	grade = s->grade;
}

bool STUDENT::operator<(const STUDENT& s) {
	return this->grade < s.grade;
}

bool STUDENT::operator>(const STUDENT& s) {
	return this->grade > s.grade;;
}

istream& operator>>(istream& istr, STUDENT& s) {
	getline(istr, s.name);
	do {
		istr >> s.grade;
	} while (s.grade < 0 && cout << "Invalid value. Please enter again!\n");
	return istr;
}

double STUDENT::get_Grade() {
	return grade;
}

ostream& operator<<(ostream& ostr, STUDENT s) {
	ostr << s.name << " " << s.grade;
	return ostr;
}

STUDENT::~STUDENT() {
}

#endif