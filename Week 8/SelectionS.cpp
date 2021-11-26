#include "SelectionS.h"

void SelectionS::Process(vector<float>& f)
{
	int min;
	int n = f.size();
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (f[j] < f[min]) 	min = j;

		if (f[min] < f[i]) swap(f[min], f[i]);
	}
}
