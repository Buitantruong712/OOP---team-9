#include "InsertionS.h"

void InsertionS::Process(float arr[], int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > key; j--) arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

