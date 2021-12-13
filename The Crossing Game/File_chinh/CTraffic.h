#ifndef _CTRAFFIC_H
#define _CTRAFFIC_H

#include "Console.h"

enum class TrafficLight {
	GREEN,
	YELLOW,
	RED
};

class CTRAFFIC {

	TrafficLight status;	// Trạng thái đèn giao thông (xanh, vàng, đỏ)
	short red_time;			// Được tính theo số lần vật di chuyển
	short yellow_time;
	short green_time;
	short mY;
	bool direction;			// true: trái -> phải => nằm bên phải, false: phải -> trái => nằm bên trái
	short X, Y;

public:
	CTRAFFIC();
	CTRAFFIC(TrafficLight, short, bool);
	CTRAFFIC(const CTRAFFIC&);
	~CTRAFFIC();

	// Setter
	void setStatus(TrafficLight value) { status = value; };
	void setTimeRed(short value) { red_time = value; };
	void setTimeYellow(short value) { yellow_time = value; };
	void setTimeGreen(short value) { green_time = value; };
	void setmY(short value) { mY = value; Y = mY * TILE_Y + (short)Border::TOP; };
	void setDirection(short value) { direction = value; setX(); };
	void setX() { X = (direction ? (short)Border::RIGHT : (short)Border::LEFT); };

	// Getter
	CTRAFFIC& operator=(const CTRAFFIC& _t);
	TrafficLight getStatus() { return status; };
	short getTimeRed() { return red_time; };
	short getTimeYellow() { return yellow_time; };
	short getTimeGreen() { return green_time; };
	short getX() { return X; };
	short getY() { return Y; };
	short getDirection() { return direction; };
	short getmY() { return mY; };

	// Thay đổi thuộc tính
	void changeStatus();	// Thay đổi status
	void runStatus();		// Chạy như đèn giao thông, có xài hàm changeStatus()

	void drawObject();
};

#endif




