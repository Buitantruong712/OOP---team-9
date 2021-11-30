#include "ProgramFrame.h"

void ProgramFrame::startMessage(ostream& os) { os << "\nWelcome to my program!\n"; }

void ProgramFrame::errorMessage(ostream& os) { os << "Input data error!\n"; }

bool ProgramFrame::askContinue(istream& is, ostream& os) {
	os << "\nPress y to continue, others to stop : ";
	char ch; is >> ch;
	return (ch == 'Y' || ch == 'y');
}

void ProgramFrame::run(istream& is, ostream& os) {
	bool b;
	do {
		startMessage(os);
		Input(is);
		if (!Check()) {
			errorMessage(os);
			break;
		}
		Process();
		Output(os);
		b = askContinue(is, os);
	} while (b);
}

