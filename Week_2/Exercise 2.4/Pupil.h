#ifndef _Pupil_h_
#define _Pupil_h_

#include <iostream>
#include <string>
using namespace std;


class Pupil {
	string fullName;
	float Math;
	float Literature;
public:
	void input();
	void output();
	float Average();
	int Type();
	void assign_fullName();
	void assign_Math();
	void assign_Literature();
};

#endif