#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
using namespace std;


class STUDENT {
	string name;
	double grade;
public:
	STUDENT();
	STUDENT(string, double);
	STUDENT(const STUDENT&);
	STUDENT(STUDENT*);
	double get_Grade();
	bool operator<(const STUDENT&);
	bool operator>(const STUDENT&);
	friend istream& operator>>(istream&, STUDENT&);
	friend ostream& operator<<(ostream&, STUDENT);

	~STUDENT();
};



#endif