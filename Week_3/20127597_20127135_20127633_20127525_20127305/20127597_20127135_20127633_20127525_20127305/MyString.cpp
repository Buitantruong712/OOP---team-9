#include "MyString.h"


int Size(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

istream& operator>>(istream& is, MyString& myS) {
	char* a = new char[1000];
	cin.getline(a, 1000);
	myS.size = Size(a);
	myS.s = new char[myS.size];
	for (int i = 0; i < myS.size;i++) {
		myS.s[i] = a[i];
	}
	myS.s[myS.size] = '\0';
	delete[] a;
	return is;
}

ostream& operator<<(ostream& os, MyString& myS) {
	os << myS.s;
	return os;
}

int MyString::length() {
	return size;
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

char* MyString::operator+( MyString newMyS) {
	int len = length() + newMyS.length();
	char* result = new char[len];
	int i = 0;
	while (i < length()) {
		result[i++] = s[i++];
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



char* MyString::insert(int pos, char* insertS) {
	int len = length() + Size(insertS);
	char* result = new char[len];
	int i = 0;
	while (i < pos) {
		result[i] = s[i];
		i++;
	}
	for (int j = 0; j < Size(insertS);j++) {
		result[i] = insertS[j];
		i++;
	}
	int k = pos;
	while (i < len) {
		result[i] = s[k];
		i++;
		k++;
	}
	result[len] = '\0';
	return result;
}

char* MyString::erase(int pos, int num) {
	int len = length() - num;
	char* newS = new char[len];
	int i = 0;
	while (i < pos) {
		newS[i] = s[i];
		i++;
	}
	int j = pos + num;
	while (i < len) {
		newS[i] = s[j];
		i++;
		j++;
	}
	newS[len] = '\0';
	return newS;
}


char* MyString::replace(int pos, int num, char* str) {
	if (pos >= strlen(c)) return c;
	char* a = new char[strlen(c) - num + strlen(str)];
	int i = 0;
	for (; i < pos; i++) a[i] = c[i];
	for (; i < pos + strlen(str); i++) a[i] = str[i - pos];
	for (; i < strlen(c) - num + strlen(str); i++) a[i] = c[i + num - strlen(str)];
	a[strlen(c) - num + strlen(str)] = '\0';
	return a;
}

bool MyString::find(int pos, char* str) {
	for (int i = pos; i <= strlen(s) - strlen(str); i++) {
		int check = 0;
		for (int j = 0; j < strlen(str); j++) {
			if (s[i + j] != str[j]) check = 1;
		}
		if (check == 0) return true;
	}
	return false;
}
