#include<iostream>
using namespace std;

class MyString {
private:
	char* c;
	int size;
public:
	MyString();
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, const MyString&);
	char* getChar();
	char* insert(int, const char*);
	char* erase(int, int);
	char* replace(int, int, char*);
	bool find(int, char*);
	~MyString();
};

MyString::MyString() {}

istream& operator>>(istream& is, MyString& my_string) {
	char* a = new char[1000];
	cout << "Enter string: ";
	is.getline(a, 1000);
	my_string.c = new char[strlen(a)];
	for (int i = 0; i < strlen(a); i++) my_string.c[i] = a[i];
	my_string.c[strlen(a)] = '\0';
	delete[] a;
	return is;
}

ostream& operator<<(ostream& os, const MyString& my_string) {
	cout << my_string.c;
	return os;
}

char* MyString::getChar() { return c; }

char* MyString::insert(int pos, const char* str) {
	char* a = new char[strlen(str) + strlen(c)];
	int i = 0;
	for (; i < pos; i++) a[i] = c[i];
	for (; i < pos + strlen(str); i++) a[i] = str[i - pos];
	for (; i < strlen(c) + strlen(str); i++) a[i] = c[i - strlen(str)];
	a[strlen(str) + strlen(c)] = '\0';
	return a;
}

char* MyString::erase(int pos, int num) {
	if (pos >= strlen(c) || num == 0) return c;
	int tmp = num;
	if (pos + tmp > strlen(c)) tmp = strlen(c) - pos;
	char* a = new char[strlen(c) - tmp];
	for (int i = 0; i < pos; i++) a[i] = c[i];
	for (int i = pos + tmp; i < strlen(c); i++) a[i - tmp] = c[i];
	a[strlen(c) - tmp] = '\0';
	return a;
}

char* MyString::replace(int pos, int num, char* str) {
	if (pos >= strlen(c)) return c;
	MyString a;
	a.c = erase(pos, num);
	a.c = a.insert(pos, str);
	return a.c;
}

bool MyString::find(int pos, char* str) {
	for (int i = pos; i <= strlen(c) - strlen(str); i++) {
		int check = 0;
		for (int j = 0; j < strlen(str); j++) {
			if (c[i + j] != str[j]) check = 1;
		}
		if (check == 0) return true;
	}
	return false;
}

MyString::~MyString() {}

int main() {
	MyString str, test;
	int pos, num;

	cout << "\nNHAP\n";
	cin >> str;
	cout << "String: " << str;

	cout << "\n\nREPLACE\n";
	cout << "Enter position: ";
	cin >> pos;
	cout << "Enter number: ";
	cin >> num;
	cin.ignore();
	cin >> test;
	cout << "Result: " << str.replace(pos, num, test.getChar());

	cout << "\n\nFIND\n";
	cout << "Enter position: ";
	cin >> pos;
	cin.ignore();
	cin >> test;
	cout << "Result: " << str.find(pos, test.getChar());

	cout << endl << endl;
}