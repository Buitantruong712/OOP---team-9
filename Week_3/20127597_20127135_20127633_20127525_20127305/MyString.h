#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
using namespace std;
#define MAX 1000

class MyString {
private:
	char* s;
	int size;
public:
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator << (ostream&, MyString&);
	int length();
	char* subString(int, int);
	char* operator+(MyString);
	char* operator+(string);
	friend char* operator+(string, MyString);
	char* insert(int, char*);
	char* erase(int, int);
	bool replace(int, int, char*);
	bool find(int, char*);
};
#endif
