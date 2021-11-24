#include "SelectionS.h"

void SelectionS::Process(float arr[], int n)
{
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min]) 	min = j;

		if (arr[min] < arr[i]) swap(arr[min], arr[i]);
	}
}
