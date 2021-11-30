#include "SATest.h"

SATest::SATest() {
	n = 0;
	SA = nullptr;
}

SATest::SATest(SortArray* sa) {
	n = 0;
	SA = sa;
}

bool SATest::Check() {
	return !(n < 1);
}

void SATest::Input(istream& is) {
	cout << "Enter a number of elements: "; is >> n;
	float a;
	for (int i = 0; i < n; i++) {
		cout << "Element " << i << " = "; cin >> a;
		f.push_back(a);
	}
}

void SATest::Output(ostream& os) {
	os << "Result after sorting: ";
	for (auto& i : f)
		os << i << " ";
}

void SATest::Process() {
	if (SA == nullptr)
		return;
	SA->Process(f);
}

SATest::~SATest() {
	f.clear();
}

