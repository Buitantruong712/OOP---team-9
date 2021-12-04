

#include "CTraffic.h"

CTraffic::CTraffic() {
	status = 0;
	timeRed = 35;
	timeYellow = 15;
	timeGreen = 70;
	trX = 0;
	trY = 0;
}

CTraffic::CTraffic(int _status , short x, short y):CTraffic() {
	status = _status;
	trX = x;
	trY = y;
}


CTraffic::CTraffic(const CTraffic& _t) {
	status = _t.status;
	timeRed = _t.timeGreen;
	timeYellow = _t.timeYellow;
	timeGreen = _t.timeGreen;
	trX = _t.trX;
	trY = _t.trY;
}

CTraffic& CTraffic::operator=(const CTraffic& _t) {
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

void CTraffic::setStatus(bool s) {
	status = s;
}

void CTraffic::setTimeRed(short t) {
	timeRed = t;
}
void CTraffic::setTimeYellow(short t) {
	timeYellow = t;
}
void CTraffic::setTimeGreen(short t) {
	timeGreen = t;
}


void CTraffic::setX(short x) {
	trX = x;
}
void CTraffic:: setY(short y) {
	trY = y;
}

bool CTraffic::getStatus() {
	return status;
}
short CTraffic::getTimeRed() {
	return timeRed;
}

short CTraffic::getTimeYellow() {
	return timeYellow;
}
short CTraffic::getTimeGreen() {
	return timeGreen;
}


short CTraffic::getX() {
	return trX;
}

short CTraffic::getY(){
	return trY;
}

void CTraffic::changeStatus() {
	if (status == 0) {
		status = 2;
	}
	else {
		status--;
	}
}

void CTraffic::draw() {
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

//void CTraffic::run(CTraffic*t1, CTraffic* t2, CTraffic*t3,short X, short Y) {
//	t1->draw(X, Y);
//	t2->draw(X, Y + 5);
//	t3->draw(X, Y + 10);
//
//	while (1) {
//		t1->changeStatus();
//		t1->draw(X, Y);
//		Sleep(10);
//		t2->changeStatus();
//		t2->draw(X, Y + 5);
//		Sleep(30);
//		t3->changeStatus();
//		t3->draw(X, Y + 10);
//	}
//}

void CTraffic::change() {
	if (status == 0) {
		timeRed--;
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
		timeRed = 35;
	}
	if (timeYellow == 0) {
		timeYellow = 15;
	}
	if (timeGreen == 0) {
		timeGreen = 70;
	}
}

CTraffic::~CTraffic() {

}
