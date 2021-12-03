#include "SortAlgorithm.h"


int main() {

	int choice = 1;
	while (choice != 0) {
		cout << "\t-------MENU------\n";
		cout << "\t0. Exit\n\t1. <float>\n\t2. <char> \n\t3. <string>\n\t4. <STUDENT>\n";
		cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1: {
			float a[] = { 1.4F,-5.2F,3.3F,0 };
			int n = sizeof(a) / sizeof(a[0]);
			SortAlgorithm<float>* alg = SortAlgorithm<float>::getObject(SortAlgorithm<float>::InterchangeSort);

			cout << "float a[] = { 1.4F ,-5.2F ,3.3F ,0 } sau khi sap xep:\n";
			alg->Sort(a, n);

			for (int i = 0; i < n; i++) {
				cout << a[i] << "\t";
			}
			cout << endl;
			break;
		}
		case 2: {
			char a[] = { 'E','B','C','D' };
			int n = sizeof(a) / sizeof(a[0]);
			SortAlgorithm<char>* alg = SortAlgorithm<char>::getObject(SortAlgorithm<char>::InterchangeSort);
			alg->Sort(a, n);

			cout << "char a[] = { 'E','B','C','D' } sau khi sap xep:\n";
			for (int i = 0; i < n;i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			break;
		}
		case 3: {
			string a[] = { "def","ghi","abc" };
			int n = sizeof(a) / sizeof(a[0]);
			SortAlgorithm<string>* alg = SortAlgorithm<string>::getObject(SortAlgorithm<string>::InterchangeSort);
			alg->Sort(a, n);

			cout << "string a[] = {" << (char)34 << "def" << (char)34 << "," << char(34) << "ghi" << (char)34 << "," << char(34) << "abc" << (char)34 << "} sau khi sap xep: \n";

			for (int i = 0; i < n;i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			break;
		}
		case 4:
		{
			STUDENT a[] = { new STUDENT("abc",8.5) , new STUDENT("def", 5.5), new STUDENT("abc",7.5) };
			int n = sizeof(a) / sizeof(a[0]);

			SortAlgorithm<STUDENT>* alg = SortAlgorithm<STUDENT>::getObject(SortAlgorithm<STUDENT>::InterchangeSort);
			alg->Sort(a, n);

			cout << "STUDENT a[] = { new STUDENT(" << (char)34 << "abc" << (char)34 << ",8.5) , new STUDENT(" << (char)34 << "def" << (char)34 << ", 5.5), new STUDENT(" << char(34) << "abc" << char(34) << ",7.5) } sau khi sap xep: \n";
			for (int i = 0; i < n;i++) {
				cout << a[i] << endl;
			}
			cout << endl;
			break;
		}
		default: {
			cout << "Invalid value\n";
			break;
		}
		}
	}
	return 0;
}