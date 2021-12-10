

#include "CTraffic.h"

CTRAFFIC::CTRAFFIC() {
	status = 0;
	timeRed = 15;
	timeYellow = 6;
	timeGreen = 65;
	trX = 0;
	trY = 0;
}

CTRAFFIC::CTRAFFIC(int _status, short x, short y) :CTRAFFIC() {
	status = _status;
	trX = x;
	trY = y;
}


CTRAFFIC::CTRAFFIC(const CTRAFFIC& _t) {
	status = _t.status;
	timeRed = _t.timeGreen;
	timeYellow = _t.timeYellow;
	timeGreen = _t.timeGreen;
	trX = _t.trX;
	trY = _t.trY;
}

CTRAFFIC& CTRAFFIC::operator=(const CTRAFFIC& _t) {
	if (this == &_t) {
		return *this;
	}
	this->status = _t.status;
	this->timeRed = _t.timeRed;
	this->timeYellow = _t.timeYellow;
	this->timeGreen = _t.timeGreen;
	this->trX = _t.trX;
	this->trY = _t.trY;
	return *this;
}

void CTRAFFIC::setStatus(bool s) {
	status = s;
}

void CTRAFFIC::setTimeRed(short t) {
	timeRed = t;
}
void CTRAFFIC::setTimeYellow(short t) {
	timeYellow = t;
}
void CTRAFFIC::setTimeGreen(short t) {
	timeGreen = t;
}


void CTRAFFIC::setX(short x) {
	trX = x;
}
void CTRAFFIC::setY(short y) {
	trY = y;
}

int CTRAFFIC::getStatus() {
	return status;
}
short CTRAFFIC::getTimeRed() {
	return timeRed;
}

short CTRAFFIC::getTimeYellow() {
	return timeYellow;
}
short CTRAFFIC::getTimeGreen() {
	return timeGreen;
}


short CTRAFFIC::getX() {
	return trX;
}

short CTRAFFIC::getY() {
	return trY;
}

void CTRAFFIC::changeStatus() {  //thay đổi trạng thái của đèn
	if (status == 0) {
		status = 2;
	}
	else {
		status--;
	}
}

void CTRAFFIC::draw() {
	short currentX = trX, currentY = trY;
	short xF = trX - 1, yF = trY - 1;
	if (status == 2) {
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF,yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ trX,trY }, (int)Color::GREEN);
		currentX = trX, currentY = trY;
	}
	else if (status == 1) {
		short y = trY + 1;
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF,yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ trX,y }, (int)Color::YELLOW);
		currentX = trX, currentY = trY + 1;
	}
	else {
		short y = trY + 2;
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF,yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ trX,y }, (int)Color::RED);
		currentX = trX, currentY = trY + 2;
	}
}



void CTRAFFIC::change() {
	draw(); 
	if (status == 0) {
		timeRed--;			//mỗi lần vật di chuyển thì thời gian giảm xuống 1
	}
	else if (status == 1) {
		timeYellow--;
	}
	else {
		timeGreen--;

	}
	if (timeRed == 0 || timeYellow == 0 || timeGreen == 0) {
		changeStatus();
		draw();
	}
	if (timeRed == 0) {
		timeRed = 15;
	}
	else if (timeYellow == 0) {
		timeYellow = 6;
	}
	else if (timeGreen == 0) {
		timeGreen = 65;
	}
}

CTRAFFIC::~CTRAFFIC() {

}