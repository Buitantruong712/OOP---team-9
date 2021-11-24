#pragma once
#include "ProgramFrame.h"
#include "SortArray.h"

class SATest : public ProgramFrame
{
private:
	int n;
	float arr[100];
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

