#ifndef _SORTALGORITHM_H_
#define _SORTALGORITHM_H_

#include <iostream>
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


#endif