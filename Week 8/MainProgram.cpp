#include "ProgramFrame.h"
#include "InsertionS.h"
#include "InterchangeS.h"
#include "SelectionS.h"
#include "SATest.h"

int main()
{
	//cout << "Selection Sort\n";
	//SATest sortTest(new SelectionS());

	//cout << "Insertion Sort\n";
	//SATest sortTest(new InsertionS());

	cout << "Interchange Sort\n";
	SATest sortTest(new InterchangeS());
	
	sortTest.run(cin, cout);
	return 0;
}