#include "Vehical.h"

Car::Car() {
	mX = mY = 0;
	mSpeed = 1;
};

Car::Car(int x, int y, int sp) {
	mX = x;
	mY = y;
	mSpeed = sp;
};

Car::Car(const Car& c) {
	mX = c.mX;
	mY = c.mY;
	mSpeed = c.mSpeed;
};

void Car::setSpeed(int sp) {
	mSpeed = sp;
}

void Car::Move() {
	mX = mX + 10;
}

Car::~Car() {};

void Car::draw(int x, int y) {
	setPos(x, y);
	int posY = mY;
	fstream f;
	f.open("Car.txt", ios::in);
	char* a = new char[MAX];
	while (!f.eof()) {
		f.getline(a, MAX, '\n');
		gotoXY(mX, posY);
		for (int i = 0; i < strlen(a); i++) {
			cout << a[i];

		}
		//cout << endl;
		posY++;
	}
	delete[]a;
	f.close();
}

void Car::deleteObj(int x, int y) {
	setPos(x, y);
	int posX = mX;
	int posY = mY;
	int i = 0;
	while (i <= 34) {
		for (int j = 0; j <= 34;j++) {
			gotoXY(posX, posY);
			cout << ' ';
			posX++;
		}
		posX = mX;
		posY++;
		i++;
	}
}

void Car::run(int x, int y) {
	setPos(x, y);
	while (mX <120) {
		draw(mX, mY);
		Sleep(1000);
		deleteObj(mX, mY);
		Move();
	}
}

//con nang cap theo level: speed ~ level
void Car::Lane(int x, int y, int speed) {
	setPos(x, y);
	while (1) {
		run(x, y);
		Sleep(2000);
		run(x, y);
	}
}