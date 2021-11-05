﻿#include"CAnimal.h"


CANIMAL::CANIMAL() {
	Y = 0;
	trueX = 0;
	setTrueCoordinates();

	setState(start);
	setDirection(false);
	setSpeed(0);
}

CANIMAL::~CANIMAL() {}


void CANIMAL::setCoordinates(short y) {
	Y = y;
}

void CANIMAL::setTrueCoordinates() {
	trueX = (direction ? MAX_MASK_X : 0);
	trueY = 2 + TILE_Y * Y;
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

	case start:
		if (running_timer-- == 0) {		// khi thời gian kết thúc => con vật bắt đầu đi
			if (not direction) {		// từ trái sang phải => di chuyển con trỏ -> vẽ
				Console::gotoXY(LEFT_BORDER, trueY);
				drawBody();
			}
			else {
				Console::gotoXY(RIGHT_BORDER, trueY);
				drawBody();
			}
			state = run;
		}
		break;

	case run:
		if (not direction) { // từ trái sang phải
			if (trueX < RIGHT_BORDER) { // nếu chưa vượt biên => xoá -> đổi toạ độ -> di chuyển con trỏ -> vẽ
				Console::removeSpace(trueX, trueY);
				trueX += speed;
				Console::gotoXY(trueX, trueY);
				drawBody();
			}
			else {	// xoá luôn, và đổi thông số
				Console::removeSpace(trueX, trueY);
				state = finish;
				trueX = LEFT_BORDER;
			}
		}

		else { // ngược lại
			if (trueX > LEFT_BORDER) {
				Console::removeSpace(trueX, trueY);
				Console::gotoXY(trueX, trueY);
				trueX -= speed;
				drawBody();
			}
			else {
				Console::removeSpace(trueX, trueY);
				state = finish;
				trueX = RIGHT_BORDER;
			}
		}
		break;

	case finish:
		state = start;
		running_timer = timer;
		break;
	}
}

void CANIMAL::setSpeed(short value) {
	speed = value;
}

short CANIMAL::getSpeed() {
	return speed;
}

void CANIMAL::setState(short value) {
	state = value;
}

short CANIMAL::getState() {
	return state;
}

void CANIMAL::setDirection(short value) {
	direction = value;
}

short CANIMAL::getDirection() {
	return direction;
}

//int CANIMAL::getCoordX() {
//	return trueX;
//}
//
//int CANIMAL::getCoordY() {
//	return trueY;
//}

void CANIMAL::setTimer(short value) {
	timer = value;
}

short CANIMAL::getTimer() {
	return timer;
}

short CANIMAL::getTrueX() {
	return trueX;
}

short CANIMAL::getVirtualY() {
	return Y;
}