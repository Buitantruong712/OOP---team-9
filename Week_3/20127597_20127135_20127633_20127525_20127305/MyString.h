#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <iostream>
using namespace std;

class MyString {
	int size = 1000;
	char* s = new char[size];
public:
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, MyString&);
	int length();
	char* subString(int, int);
	char* operator+(MyString);
	friend char* operator+(MyString, string);
	friend char* operator+(string, MyString);
	bool insert(int, char*);
	bool erase(int, int);
	bool replace(int, int, char*);
	bool find(int, char*);
};
#endif // !_MYSTRING_H
