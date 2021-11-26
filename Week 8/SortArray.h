#pragma once
#include<iostream>
using namespace std;

class SortArray
{
public:
	SortArray();
	virtual void Process(float arr[], int n) = 0;
	~SortArray();
};

