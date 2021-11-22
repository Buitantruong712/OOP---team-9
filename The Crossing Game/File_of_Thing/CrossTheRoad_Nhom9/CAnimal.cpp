#include"CAnimal.h"


CANIMAL::CANIMAL() {
	Y = 0;
	trueX = 0;
	setTrueCoordinates();

	setDirection(false);
	setSpeed(0);
}

CANIMAL::~CANIMAL() {}


void CANIMAL::setTrueX(short x) {
	trueX = x;
}


void CANIMAL::setY(short y) {
	Y = y;
}

void CANIMAL::setTrueCoordinates() {
	trueX = (direction ? MAX_MASK_X : 0);
	trueY = 1 + TILE_Y * Y;
}

void CANIMAL::drawBody() {
	Console::drawFromFile(
		sprite,
		COORD{ trueX, trueY },
		(int)Color::yellow
	);
}



void CANIMAL::cMove() {

	switch (state) {

	case AnimalState::start:
		if (running_timer-- == 0) {		// khi thời gian kết thúc => con vật bắt đầu đi
			if (not direction) {		// từ trái sang phải => di chuyển con trỏ -> vẽ
				Console::gotoXY(LEFT_BORDER, trueY);
				drawBody();
			}
			else {
				Console::gotoXY(RIGHT_BORDER, trueY);
				drawBody();
			}
			state = AnimalState::run;
		}
		break;

	case AnimalState::run:
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
				state = AnimalState::finish;
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
				state = AnimalState::finish;
				trueX = RIGHT_BORDER;
			}
		}
		break;

	case AnimalState::finish:
		state = AnimalState::start;
		running_timer = timer;
		break;
	}
}

void CANIMAL::setSpeed(short value) {
	speed_delay = value;
	running_delay = speed_delay;
}

short CANIMAL::getSpeed() {
	return speed_delay;
}

void CANIMAL::setState(AnimalState value) {
	state = value;
}

AnimalState CANIMAL::getState() {
	return state;
}

void CANIMAL::setDirection(short value) {
	direction = value;
}

short CANIMAL::getDirection() {
	return direction;
}

void CANIMAL::setTimer(short value) {
	timer = value;
}

void CANIMAL::setRunningTimer(short value) {
	running_timer = value;
}

short CANIMAL::getTimer() {
	return timer;
}

short CANIMAL::getRunningTimer() {
	return running_timer;
}

short CANIMAL::getTrueX() {
	return trueX;
}

short CANIMAL::getY() {
	return Y;
}
