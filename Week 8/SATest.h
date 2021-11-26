#pragma once
#include "ProgramFrame.h"
#include "SortArray.h"

class SATest : public ProgramFrame
{
private:
	int n;
	vector<float> f;
	SortArray* SA;
public:
	SATest();
	SATest(SortArray*);
	bool Check();
	void Input(istream&);
	void Output(ostream&);
	void Process();
	~SATest();
};

