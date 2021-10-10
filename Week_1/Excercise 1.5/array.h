#ifndef _MY_FUNCTION
#define _MY_FUNCTION

#include <iostream>
using namespace std;
#define MAX 100

struct Array {
	int a[MAX];
	int size;
};
Array input();
void output(Array a);
int getSize(Array a);
int getItem(Array a, int pos);
bool findItem(Array a, int item);
void compare_swap(int& a, int& b);
void sortIncrease(Array& a);
void sortDecrease(Array& a);
#endif


