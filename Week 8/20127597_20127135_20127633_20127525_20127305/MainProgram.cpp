#include "ProgramFrame.h"
#include "InsertionS.h"
#include "InterchangeS.h"
#include "SelectionS.h"
#include "SATest.h"

int main()
{

	cout << "\nSelection Sort";
	SATest sortTest1(new SelectionS());
	sortTest1.run(cin, cout);

	cout << "\nInsertion Sort";
	SATest sortTest2(new InsertionS());
	sortTest2.run(cin, cout);

	cout << "\nInterchange Sort";
	SATest sortTest3(new InterchangeS());
	sortTest3.run(cin, cout);
	return 0;
}