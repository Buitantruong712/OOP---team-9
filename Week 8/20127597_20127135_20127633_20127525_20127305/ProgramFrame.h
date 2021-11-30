#pragma once
#include <iostream>
using namespace std;

class ProgramFrame {
protected:
	virtual void startMessage(ostream&);
	virtual void errorMessage(ostream&);
	virtual bool askContinue(istream&, ostream&);
	virtual void Input(istream&) = 0;
	virtual void Output(ostream&) = 0;
	virtual bool Check() = 0;
	virtual void Process() = 0;
public:
	void run(istream&, ostream&);
};
