#include "Pupil.h"

int main() {
	Pupil a;
	cout << "---------Input the information of the pupil" << endl;
	a.input();
	a.output();

	int choice = 1;
	while (choice != 0) {
		cout << "\nDo you want assign a value?\t0.No\n\t\t\t\t1.Full Name\n\t\t\t\t2.Math grades\n\t\t\t\t3.Literature grades\n" ;
		cin >> choice;
		switch (choice) {
		case 0: 
			break;
		case 1:
			a.assign_fullName();
			break;
		case 2:
			a.assign_Math();
			break;
		case 3:
			a.assign_Literature();
			break;
		default:
			cout << "Invalid value! Input again ";
			cin >> choice;
		}
	}
	a.output();
	cout << "Average: " << a.Average() << endl;
	a.Type();
	return 0;
}