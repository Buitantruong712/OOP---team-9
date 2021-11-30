#include "InsertionS.h"

void InsertionS::Process(vector<float>& f) {
	int key, j;
	int n = f.size();
	for (int i = 1; i < n; i++) {
		key = f[i];
		int j = i - 1;
		for (; j >= 0 && f[j] > key; j--) f[j + 1] = f[j];
		f[j + 1] = key;
	}
}
