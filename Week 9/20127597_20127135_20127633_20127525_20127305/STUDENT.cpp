#include "STUDENT.h"


STUDENT::STUDENT() {
	name = " ";
	grade = 0;
}
STUDENT::STUDENT(string _name, double _grade) {
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
	if (this->grade < s.grade) {
		return true;
	}
	else if (this->grade > s.grade) {
		return false;
	}
}

bool STUDENT::operator>(const STUDENT& s) {
	if (this->grade > s.grade) {
		return true;
	}
	else if (this->grade < s.grade) {
		return false;
	}
}

istream& operator>>(istream& istr, STUDENT& s) {
	istr >> s.name;
	do {
		istr >> s.grade;
	} while (s.grade < 0);
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
