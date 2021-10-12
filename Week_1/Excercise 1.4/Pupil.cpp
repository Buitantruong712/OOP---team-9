#include <iostream>
#include "Pupil.h"
using namespace std;


pupil input(pupil &a) {
	cout << "Enter name: ";
	cin.getline(a.name, 30, '\n');
	cout << "Enter math grades: ";
	cin >> a.math;
	while (a.math < 0 || a.math>10) {
		cout << "Input wrong! Enter math grades again: ";
		cin >> a.math;
	}
	cout << "Enter literature grades: ";
	cin >> a.literature;
	while (a.literature < 0 || a.literature>10) {
		cout << "Input wrong! Enter literature grades again: ";
		cin >> a.literature;
	}
	return a;
}

void output(pupil a) {
	cout << "\nFull name: " << a.name;
	cout << "\nMath: " << a.math << "      Literature: " << a.literature << endl;
}

float Average(pupil a) {
	return (a.math + a.literature) / 2;
}

void Run() {
	pupil a;
	input(a);
	output(a);
	cout << "Average = " << Average(a) << endl;
	if (Average(a) < 5.) cout << "Weak";
	else if (Average(a) < 7.) cout << "Not bad";
	else if (Average(a) < 8.) cout << "Good";
	else cout << "Excellent";
}