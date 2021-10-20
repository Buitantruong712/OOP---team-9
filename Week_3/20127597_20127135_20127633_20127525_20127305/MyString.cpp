#include "MyString.h"

istream& operator>>(istream& is, MyString& myS) {
	cin.getline(myS.s, myS.size);
	return is;
}

ostream& operator<<(ostream& os, MyString& myS) {
	os << myS.s;
	return os;
}

int MyString::length() {
	return strlen(s);
}

char* MyString::subString(int start, int len) {
	char* sub = new char[len];
	int i = 0;
	while (i < len) {
		sub[i++] = s[start++];
	}
	sub[len] = '\0';
	return sub;
}

char* MyString::operator+(MyString newMyS) {
	int len = length() + newMyS.length();
	char* result = new char[len];
	int i = 0;
	while (i < length()) {
		result[i] = s[i++];
	}
	int j = 0;
	while (j < newMyS.length()) {
		result[i++] = newMyS.s[j++];
	}
	result[len] = '\0';
	return result;
}

char* operator+(MyString myS, string newS) {
	int len = myS.length() + newS.length();
	char* result = new char[len];
	int i = 0;
	while (i < myS.length()) {
		result[i] = myS.s[i];
		i++;
	}
	int j = 0;
	while (j < newS.length()) {
		result[i++] = newS[j++];
	}
	result[len] = '\0';
	return result;
}

char* operator+(string newS, MyString myS) {
	int len = myS.length() + newS.length();
	char* result = new char[len];
	int i = 0;
	while (i < newS.length()) {
		result[i] = newS[i]; 
		i++;
	}
	int j = 0;
	while (j < myS.length()) {
		result[i++] = myS.s[j++];
	}
	result[len] = '\0';
	return result;
}