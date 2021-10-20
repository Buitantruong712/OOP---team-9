#include "MyString.h"

int main() {
	MyString s, t;
	cin >> s >> t;
	cout << s << endl;
	cout << s.length() << endl;
	cout << s.subString(2, 3) << endl;
	cout << s + " " + t << endl;
	return 0;
}