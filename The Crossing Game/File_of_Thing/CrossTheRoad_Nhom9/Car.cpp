#include "CVehicle.h"


Car::Car(short y, bool direction, short speed_delay) {
	Y = y;
	setTrueCoordinates();
	setState(VehicleState::start);
	setDirection(direction);
	setSpeed(speed_delay);
	setTimer(0);
	running_timer = timer;
	this->index = index;
	sprite = (direction == false ? "mobs/car_left.txt" : "mob/car_right.txt");
}


void Car::setIndex(short value) {
	index = value;
	timer += 200 * value;
	running_timer = timer;
}

short Car::getIndex() {
	return index;
}


//void Car::draw(int x, int y) {
//	setPos(x, y);
//	int posY = mY;
//	fstream f;
//	f.open("Car.txt", ios::in);
//	char* a = new char[MAX];
//	while (!f.eof()) {
//		f.getline(a, MAX, '\n');
//		gotoXY(mX, posY);
//		for (int i = 0; i < strlen(a); i++) {
//			cout << a[i];
//
//		}
//		//cout << endl;
//		posY++;
//	}
//	delete[]a;
//	f.close();
//}
//
//void Car::deleteObj(int x, int y) {
//	setPos(x, y);
//	int posX = mX;
//	int posY = mY;
//	int i = 0;
//	while (i <= 34) {
//		for (int j = 0; j <= 34; j++) {
//			gotoXY(posX, posY);
//			cout << ' ';
//			posX++;
//		}
//		posX = mX;
//		posY++;
//		i++;
//	}
//}
//
//void Car::run(int x, int y) {
//	setPos(x, y);
//	while (mX < 120) {
//		draw(mX, mY);
//		Sleep(1000);
//		deleteObj(mX, mY);
//		Move();
//	}
//}
//
////con nang cap theo level: speed ~ level
//void Car::Lane(int x, int y, int speed) {
//	setPos(x, y);
//	while (1) {
//		run(x, y);
//		Sleep(2000);
//		run(x, y);
//	}
//}