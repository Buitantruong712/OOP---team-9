#ifndef _CTRAFFIC_H
#define _CTRAFFIC_H

#include "Console.h"

class CTraffic {
private:
	int status;	//0: do   1:vang    2: xanh
	short timeRed; // theo level
	short timeYellow;
	short timeGreen;
	short trX = 2;
	short trY;
public:
	CTraffic();
	CTraffic(int _status, short, short);
	CTraffic(const CTraffic&);

	void setStatus(bool);
	void setTimeRed(short);
	void setTimeYellow(short);
	void setTimeGreen(short);
	void setX(short);
	void setY(short);
	CTraffic& operator=(const CTraffic& _t);
	bool getStatus();
	short getTimeRed();
	short getTimeYellow();
	short getTimeGreen();
	short getX();
	short getY();

	void changeStatus();
	void change();

	void draw();
	void run(CTraffic* t1, CTraffic* t2, CTraffic* t3, short X, short Y);
	~CTraffic();
};

#endif



