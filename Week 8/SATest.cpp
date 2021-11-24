#include "SATest.h"


SATest::SATest() {}
SATest::SATest(SortArray* sa) { SA = sa; }

bool SATest::Check() {
	if (n <= 0) return false;
	return true;
}

void SATest::Input(istream& is) {
	cout << "Nhap so phan tu: ";
	is >> n;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		is >> arr[i];
	}
}

void SATest::Output(ostream& os) {
	for (int i = 0; i < n; i++)	os << arr[i] << " ";
}

void SATest::Process() { SA->Process(arr, n); }
SATest::~SATest() {}

