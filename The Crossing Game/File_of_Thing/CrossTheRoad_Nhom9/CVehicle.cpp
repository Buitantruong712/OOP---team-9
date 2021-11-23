#include "CVehicle.h"


CVEHICLE::CVEHICLE() {
	Y = 0;
	trueX = 0;
	setTrueCoordinates();

	setDirection(false);
	setSpeed(0);
}

//CVEHICLE::CVEHICLE(short x, short y, short s) {
//	mX = x;
//	mY = y;
//	mSpeed = s;
//}
//
//CVEHICLE::CVEHICLE(const CVEHICLE& v) {
//	mX = v.mX;
//	mY = v.mY;
//	mSpeed = v.mSpeed;
//}

CVEHICLE::~CVEHICLE() {

};


void CVEHICLE::setTrueX(short x) {
	trueX = x;
}


void CVEHICLE::setY(short y) {
	Y = y;
}

void CVEHICLE::setTrueCoordinates() {
	trueX = (direction ? MAX_MASK_X : 0);
	trueY = 1 + TILE_Y * Y;
}

void CVEHICLE::drawBody() {
	Console::drawFromFile(
		sprite,
		COORD{ trueX, trueY },
		(int)Color::yellow
	);
}



void CVEHICLE::cMove() {

	switch (state) {

	case VehicleState::start:
		if (running_timer-- == 0) {		// khi thời gian kết thúc => con vật bắt đầu đi
			if (not direction) {		// từ trái sang phải => di chuyển con trỏ -> vẽ
				Console::gotoXY(LEFT_BORDER, trueY);
				drawBody();
			}
			else {
				Console::gotoXY(RIGHT_BORDER, trueY);
				drawBody();
			}
			state = VehicleState::run;
		}
		break;

	case VehicleState::run:
		if (not direction) { // từ trái sang phải
			if (trueX < RIGHT_BORDER) { // nếu chưa vượt biên => xoá -> đổi toạ độ -> di chuyển con trỏ -> vẽ
				Console::removeSpace(trueX, trueY);

				if (running_delay-- == 0) {
					trueX++;
					running_delay = speed_delay;
				}
				Console::gotoXY(trueX, trueY);
				drawBody();
			}
			else {	// xoá luôn, và đổi thông số
				Console::removeSpace(trueX, trueY);
				state = VehicleState::finish;
				trueX = LEFT_BORDER;
			}
		}

		else { // ngược lại
			if (trueX > LEFT_BORDER) {
				Console::removeSpace(trueX, trueY);
				Console::gotoXY(trueX, trueY);
				if (running_delay-- == 0) {
					trueX--;
					running_delay = speed_delay;
				}
				drawBody();
			}
			else {
				Console::removeSpace(trueX, trueY);
				state = VehicleState::finish;
				trueX = RIGHT_BORDER;
			}
		}
		break;

	case VehicleState::finish:
		state = VehicleState::start;
		running_timer = timer;
		break;
	}
}

void CVEHICLE::setSpeed(short value) {
	speed_delay = value;
	running_delay = speed_delay;
}

short CVEHICLE::getSpeed() {
	return speed_delay;
}

void CVEHICLE::setState(VehicleState value) {
	state = value;
}

VehicleState CVEHICLE::getState() {
	return state;
}

void CVEHICLE::setDirection(short value) {
	direction = value;
}

short CVEHICLE::getDirection() {
	return direction;
}

void CVEHICLE::setTimer(short value) {
	timer = value;
}

void CVEHICLE::setRunningTimer(short value) {
	running_timer = value;
}

short CVEHICLE::getTimer() {
	return timer;
}

short CVEHICLE::getRunningTimer() {
	return running_timer;
}

short CVEHICLE::getTrueX() {
	return trueX;
}

short CVEHICLE::getY() {
	return Y;
}
