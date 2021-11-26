#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

class SortArray
{
public:
	SortArray();
	virtual void Process(float arr[], int n) = 0;
	~SortArray();
};

