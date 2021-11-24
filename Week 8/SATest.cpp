#include "SATest.h"


SATest::SATest() {}
SATest::SATest(SortArray* pAlg) { SA = pAlg; }

bool SATest::Check() {
	if (n <= 0) return false;
	return true;
}

void SATest::Input(istream& is) {
	do {
		cout << "Nhap so phan tu: ";
		is >> n;
	} while (n < 1 && cout << "Khong hop le! Nhap lai\n");
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

