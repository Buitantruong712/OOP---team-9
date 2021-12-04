#ifndef _CTRUCK_H
#define _CTRUCK_H

#include "CVehicle.h"
#include "CTraffic.h"

class CTRUCK : public CVEHICLE {
private:
public:
	CTRUCK();
	CTRUCK(short, bool);
	~CTRUCK();

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };
	// Minh họa
	virtual void drawBody();
	virtual void move();
};

#endif