#ifndef _Pupil_h_
#define _Pupil_h_

struct pupil {
	char name[30];
	float math, literature;
};

pupil input(pupil& a);
void output(pupil a);
float Average(pupil a);
void Run();

#endif