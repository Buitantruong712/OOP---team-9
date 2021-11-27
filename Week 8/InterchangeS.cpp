#include "InterchangeS.h"

void InterchangeS::Process(vector<float> &f) {
	int n = f.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (f[i] > f[j]) swap(f[i], f[j]);
}
