#include "MyString.h"

istream& operator>>(istream& is, MyString& myS) {
	char* a = new char[1000];
	cin.getline(a, 1000);
	myS.size = strlen(a);
	myS.s = new char[myS.size+1];
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
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
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

// MyString + MyString
char* MyString::operator+(MyString newMyS) {
	int len = length() + newMyS.length();
	char* result = new char[len];
	int i = 0;
	while (i < length()) {
		result[i++] = s[i++];
	}
	int j = 0;
	while (i < len) {
		result[i++] = newMyS.s[j++];
	}
	result[len] = '\0';
	return result;
}

// MyString + string
char* operator+(MyString myS, string newS) {
	int len = myS.length() + newS.length();
	char* result = new char[len];
	int i = 0;
	while (i < myS.length()) {
		result[i] = myS.s[i];
		i++;
	}
	int j = 0;
	while (i < len) {
		result[i++] = newS[j++];
	}
	result[len] = '\0';
	return result;
}

// string + MyString
char* operator+(string newS, MyString myS) {
	int len = myS.length() + newS.length();
	char* result = new char[len];
	int i = 0;
	while (i < newS.length()) {
		result[i] = newS[i];
		i++;
	}
	int j = 0;
	while (i < len) {
		result[i++] = myS.s[j++];
	}
	result[len] = '\0';
	return result;
}

char* MyString::insert(int pos, char* insertS) {
	int len = length() + strlen(insertS);
	char* result = new char[len + 1];
	int i = 0;
	while (i < pos) {
		result[i] = s[i];
		i++;
	}
	for (int j = 0; j < strlen(insertS);j++) {
		result[i] = insertS[j];
		i++;
	}
	for (int j = pos;j < length();j++) {
		result[i] = s[j];
		i++;
	}
	result[len] = '\0';
	delete[]s;
	s = new char[len + 1];
	for (int j = 0; j < len;j++) {
		s[j] = result[j];
	}
	s[len] = '\0';
	delete[]result;
	return s;
}

char* MyString::erase(int pos, int num) {
	int len = length() - num;
	char* newS = new char[len+1];
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
	delete[]s;
	s = new char[len + 1];
	for (int k = 0; k < len;k++) {
		s[k] = newS[k];
	}
	s[len] = '\0';
	delete[] newS;
	return s;
}

bool MyString::replace(int pos, int num, char* str) {
	if (pos+num >= length() || pos<0 || num <0) return false;
	char* a = new char[length() - num + strlen(str) + 1];
	int i = 0;
	for (; i < pos; i++) a[i] = s[i];
	for (; i < pos + strlen(str); i++) a[i] = str[i - pos];
	for (; i < length() - num + strlen(str); i++) a[i] = s[i + num - strlen(str)];
	a[length() - num + strlen(str)] = '\0';
	delete[] s;
	s = new char[strlen(a) + 1];
	for (int j = 0; j < strlen(a); j++) s[j] = a[j];
	s[strlen(a)] = '\0';
	delete[] a;
	return true;
}

bool MyString::find(int pos, char* str) {
	for (int i = pos; i <= length() - strlen(str); i++) {
		int check = 1;
		for (int j = 0; j < strlen(str); j++) {
			if (s[i + j] != str[j]) check = 0;
		}
		if (check) return true;
	}
	return false;
}
