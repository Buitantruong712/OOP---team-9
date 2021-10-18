#ifndef _MYARRAY_H
#define _MYARRAY_H

#include <iostream>
using namespace std;

#define MAX 100

class MyArray {
	int a[MAX];
	short size;
public:
	void Input();
	void Output();
	unsigned short Size();
	int Get(unsigned short);
	bool Find(int);
	void sortIncrease();
	void sortDecrease();
};

// support for sort functions
void compare_swap(int& a, int& b);

#endif 
