#include "Vehical.h"


Truck::Truck() {
	mX = mY = 0;
	mSpeed = 1;
};

Truck::Truck(int x, int y, int sp) :Vehical(x, y, sp) {
};

Truck::Truck(const Truck& tr) :Vehical(tr) {};
void Truck::setSpeed(int sp) {
	mSpeed = sp;
};

void Truck::Move() {
		mX = mX - 10;
}

Truck::~Truck() {};

void Truck::draw(int x, int y) {
	setPos(x, y);
	int posY = mY;
	fstream f;
	f.open("Truck.txt", ios::in);
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

void Truck::deleteObj(int x, int y) {
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

void Truck::run(int x, int y) {
	setPos(x, y);
	while (mX > 0) {
		draw(mX, mY);
		Sleep(1000);
		deleteObj(mX, mY);
		Move();
	}
}

//con nang cap theo level: speed ~ level
void Truck::Lane(int x, int y, int speed) {
	setPos(x, y);
	while (1) {
		run(x, y);
		Sleep(2000);
		run(x, y);
	}
}