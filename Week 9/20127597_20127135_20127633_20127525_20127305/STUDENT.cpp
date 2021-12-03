#include "STUDENT.h"


STUDENT::STUDENT() {
	name = " ";
	grade = 0;
}
STUDENT::STUDENT(string _name, double _grade) {
	if (_grade < 0)
		_grade = 0;
	name = _name;
	grade = _grade;
}

STUDENT::STUDENT(const STUDENT& s) {
	name = s.name;
	grade = s.grade;
}


STUDENT::STUDENT(STUDENT* s) {
	name = s->name;
	grade = s->grade;
}

bool STUDENT::operator<(const STUDENT& s) {
	return this->grade < s.grade;
}

bool STUDENT::operator>(const STUDENT& s) {
	return this->grade >s.grade;;
}

istream& operator>>(istream& istr, STUDENT& s) {
	getline(istr, s.name);
	do {
		istr >> s.grade;
	} while (s.grade < 0 && cout << "Invalid value. Please enter again!\n");
	return istr;
}

double STUDENT::get_Grade() {
	return grade;
}

ostream& operator<<(ostream& ostr, STUDENT s) {
	ostr << s.name << " " << s.grade;
	return ostr;
}

STUDENT::~STUDENT() {
}
