#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
using namespace std;
const int MAX = 100;

int Size(char*);

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
	friend char* operator+(MyString, string);
	friend char* operator+(string, MyString);
	char* insert(int, char*);
	char* erase(int, int);
	char* replace(int, int, char*);
	bool find(int, char*);
};



#endif