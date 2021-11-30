#pragma once
#include "SortArray.h"

SortArray::SortArray(){}

class SelectionS : public SortArray
{
public:
	void Process(vector<float>& f);
};

SortArray::~SortArray(){}
