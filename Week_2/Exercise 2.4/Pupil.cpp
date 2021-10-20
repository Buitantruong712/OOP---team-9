#include "Pupil.h"

void Pupil::input() {
	cout << "Enter full name: ";
	getline(cin, fullName);
	cout << "Enter math grades: ";
	cin >> Math;
	while (Math < 0 || Math >10) {
		cout << "Input wrong! Enter math grades again: ";
		cin >> Math;
	}
	cout << "Enter literature grades: ";
	cin >> Literature;
	while (Literature < 0 || Literature>10) {
		cout << "Input wrong! Enter literature grades again: ";
		cin >> Literature;
	}
}

void Pupil::output() {
	cout << "\n=> Output:\tFull name: " << fullName;
	cout << "\n\t\tMath: " << Math << "\n\t\tLiterature: " << Literature << endl;
}

float Pupil::Average() {
	return (Math + Literature) / 2;
}

int Pupil::Type() {
	if (Average() < 5) {
		cout << "Type: weak";
		return 4;
	}
	else if (Average() < 7) {
		cout << "Type: Average";
		return 3;
	}
	else if (Average() < 8) {
		cout << "Type: Good";
		return 2;
	}
	else {
		cout << "Type: Excellent";
		return 1;
	}
}

void Pupil::assign_fullName() {
	string a;
	cout << "Enter full name: ";
	cin.ignore();
	getline(cin, a);
	fullName = a;
}

void Pupil::assign_Math() {
	float math;
	cout << "Enter math grades: ";
	cin >> math;
	Math = math;
	while (Math < 0 || Math >10) {
		cout << "Input wrong! Enter math grades again: ";
		cin >> Math;
	}
}

void Pupil::assign_Literature() {
	float literature;
	cout << "Enter literature grades: ";
	cin >> literature;
	Literature = literature;
	while (Literature < 0 || Literature>10) {
		cout << "Input wrong! Enter literature grades again: ";
		cin >> Literature;
	}
}

