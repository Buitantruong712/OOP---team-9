#ifndef _CTRAFFIC_H
#define _CTRAFFIC_H

#include "Console.h"

class CTRAFFIC {
private:
	int status;	//0: đỏ   1:vàng    2: xanh
	short timeRed;			//được tính theo số lần vật di chuyển
	short timeYellow;
	short timeGreen;
	short trX;
	short trY;
public:
	CTRAFFIC();
	CTRAFFIC(int _status, short, short);
	CTRAFFIC(const CTRAFFIC&);

	void setStatus(bool);
	void setTimeRed(short);
	void setTimeYellow(short);
	void setTimeGreen(short);
	void setX(short);
	void setY(short);

	CTRAFFIC& operator=(const CTRAFFIC& _t);
	int getStatus();
	short getTimeRed();
	short getTimeYellow();
	short getTimeGreen();
	short getX();
	short getY();

	void changeStatus();
	void change();

	void draw();
	~CTRAFFIC();
};

#endif




