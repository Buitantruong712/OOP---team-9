#include "Vehical.h"


Vehical::Vehical() {
	mX = mY = 0;
	mSpeed = 1;
}


Vehical::Vehical(int x, int y, int s) {
	mX = x;
	mY = y;
	mSpeed = s;
}
Vehical::Vehical(const Vehical& v) {
	mX = v.mX;
	mY = v.mY;
	mSpeed = v.mSpeed;
}

int Vehical::Get_mX() {
	return mX;
}
int Vehical::Get_mY() {
	return mY;
}

int Vehical::Get_mSpeed() {
	return mSpeed;
}

Vehical::~Vehical() {};


void Vehical::setPos(int x, int y) {
	mX = x;
	mY = y;
}

void Vehical::setSpeed(int speed) {
	mSpeed = speed;
}

void Vehical::changeSpeed(int change) {
	mSpeed += change;
}

//1: sang trai __ lan truck se di sang trai
//0: sang phai __ lan car se di sang phai  ==> 2 lan xen ke nhau
void Vehical::Move(int huong) {
	if (huong == 0) {
		mX = mX + 10;
	}
	else if (huong == 1) {
		mX = mX - 10;
	}
}
