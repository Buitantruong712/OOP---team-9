#include "CTraffic.h"

CTRAFFIC::CTRAFFIC() {
	status = TrafficLight::RED;
	red_time = 15;
	yellow_time = 6;
	green_time = 65;
	mY = 0;
	direction = false;
	X = 0;
	Y = 0;
}

CTRAFFIC::CTRAFFIC(TrafficLight status, short mY, bool direction) : CTRAFFIC() {
	this->status = status;
	this->direction = direction;
	setmY(mY);
	setX();
}


CTRAFFIC::CTRAFFIC(const CTRAFFIC& _t) {
	status = _t.status;
	red_time = _t.green_time;
	yellow_time = _t.yellow_time;
	green_time = _t.green_time;
	X = _t.X;
	Y = _t.Y;
	direction = _t.direction;
	mY = _t.mY;

}

CTRAFFIC& CTRAFFIC::operator=(const CTRAFFIC& _t) {
	if (this == &_t) {
		return *this;
	}
	this->status = _t.status;
	this->red_time = _t.red_time;
	this->yellow_time = _t.yellow_time;
	this->green_time = _t.green_time;
	this->X = _t.X;
	this->Y = _t.Y;
	this->direction = direction;
	this->mY = _t.mY;
	return *this;
}

void CTRAFFIC::drawObject() {
	short currentX = X, currentY = Y;
	short xF = X - 1, yF = Y - 1;
	if (status == TrafficLight::GREEN) {
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF, yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ X, Y }, (int)Color::GREEN);
		currentX = X, currentY = Y;
	}
	else if (status == TrafficLight::YELLOW) {
		short y = Y + 1;
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF,yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ X,y }, (int)Color::YELLOW);
		currentX = X, currentY = Y + 1;
	}
	else {
		short y = Y + 2;
		Console::removeSpace(currentX, currentY);
		Console::drawFromFile("Traffic/FrameTraffic.txt", COORD{ xF,yF }, (int)Color::WHITE);
		Console::drawFromFile("Traffic/Traffic.txt", COORD{ X,y }, (int)Color::RED);
		currentX = X, currentY = Y + 2;
	}
}



void CTRAFFIC::runStatus() {
	drawObject(); 
	if (status == TrafficLight::RED) {
		red_time--;			//mỗi lần vật di chuyển thì thời gian giảm xuống 1
	}
	else if (status == TrafficLight::YELLOW) {
		yellow_time--;
	}
	else {
		green_time--;
	}

	if (red_time == 0 || yellow_time == 0 || green_time == 0) {
		changeStatus();
		drawObject();
	}

	if (red_time == 0) {
		red_time = 15;
	}

	else if (yellow_time == 0) {
		yellow_time = 6;
	}

	else if (green_time == 0) {
		green_time = 65;
	}
}

void CTRAFFIC::changeStatus() {  //thay đổi trạng thái của đèn
	if (status == TrafficLight::RED) {
		status = TrafficLight::GREEN;
	}
	else if (status == TrafficLight::GREEN) { // 
		status = TrafficLight::YELLOW;
	}
	else {
		status = TrafficLight::RED;
	}
}

CTRAFFIC::~CTRAFFIC() {

}