#include "MyString.h"

int main() {
	MyString s;
	cout << "Enter string s: ";
	cin >> s;
	cout << "s: " << s << endl << "Length: " << s.length() << endl;
	int choice = 1;
	while (choice != 0) {
		cout << "\nChoice:\t0.Exit\n\t1.Sub-string\n\t2.Insert a new string\n\t3.Delete a sub-string\n\t4.Replace a string with a new string\n\t5.Find a sub-string\n\t6.Operator+ a new string into current string\n";
		cin >> choice;
		int pos = 0, num = 0;
		switch (choice) {
		case 1:
			cout << "\n\t-----Sub-string (s = " << s << ")----- " << endl;
			do {
				cout << "Enter starting position: ";
				cin >> pos;
				cout << "number of sub-string: ";
				cin >> num;
				if ((pos + num) > s.length() || pos < 0 || num < 0) {
					cout << "Invalid value! Enter again\n";
				}
			} while ((pos + num) > s.length() || pos < 0 || num < 0);
			cout << s.subString(pos, num) << endl;
			break;
		case 2:
		{cout << "\n\t-----Insert a new string (s = " << s << ") ---- - " << endl;
		char* insertS = new char[MAX];
		do {
			cout << "Enter the POSITION where to insert: ";
			cin >> pos;
			cin.ignore();
			cout << "Enter the string you want to insert: ";
			cin.getline(insertS, MAX);
			if (pos > s.length() - 1 || pos < 0) {
				cout << "Invalid value! Enter again\n";
			}
		} while (pos > s.length() - 1 || pos < 0);
		cout << s.insert(pos, insertS) << endl;
		break;}
		case 3:
			cout << "\n\t-----Delete a sub-string (s = " << s << ")----- " << endl;
			do {
				cout << "Enter starting position: ";
				cin >> pos;
				cout << "Enter number of characters need erasing: ";
				cin >> num;
				if (pos < 0 || num<0 || (pos + num)>s.length()) {
					cout << "Invalid value! Enter again\n";
				}
			} while (pos < 0 || num<0 || (pos + num)>s.length());
			cout << s.erase(pos, num) << endl;
			break;
		case 4: {
			cout << "\n\t-----Replace a string with a new string (s = " << s << ")----- " << endl;
			char* replaceS = new char[MAX];
			do {
				cout << "Enter starting position: ";
				cin >> pos;
				cout << "Enter number of characters need replacing: ";
				cin >> num;
				cin.ignore();
				cout << "Enter the string you want to replace: ";
				cin.getline(replaceS, MAX);
				if (pos < 0 || num<0 || (pos + num)>s.length()) {
					cout << "Invalid value! Enter again\n";
				}
			} while (pos < 0 || num<0 || (pos + num)>s.length());
			cout << s.replace(pos, num, replaceS) << endl;
			break;}
		case 5: {
			cout << "\n\t-----Find a sub-string (s = " << s << ")----- " << endl;
			char* searchS = new char[MAX];
			do {
				cout << "Enter starting position: ";
				cin >> pos;
				cout << "Enter the string you need to search: ";
				cin.ignore();
				cin.getline(searchS, MAX);
				if (pos < 0) {
					cout << "Invalid value! Enter again\n";
				}
			} while (pos < 0);
			if (s.find(pos, searchS) == 1) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			break;}
		case 6: {
			MyString t;
			cout << "\n\t-----Operator+ (s = " << s << ")----- " << endl;
			cout << "Enter string t: ";
			cin.ignore();
			cin >> t;
			cout << "s + " << (char)34 << " " << (char)34 << " + t = " << s + " " + t << endl;
		}
		case 0:	break;
		default:
			cout << "Invalid value! " << endl;
		}
	}
	return 0;
}