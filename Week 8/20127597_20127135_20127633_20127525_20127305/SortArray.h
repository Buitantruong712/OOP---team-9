#pragma once
#include<iostream>
#include<vector>
using namespace std;

class SortArray
{
public:
	SortArray();
	virtual void Process(vector<float>& f) = 0;
	~SortArray();
};
