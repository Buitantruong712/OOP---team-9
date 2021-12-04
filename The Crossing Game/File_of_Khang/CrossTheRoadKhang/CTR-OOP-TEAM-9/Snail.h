#pragma once

#include "CAnimal.h"

class CSNAIL : public CANIMAL {
private:
public:
	CSNAIL();
	CSNAIL(short, bool);
	~CSNAIL();

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };
	// Minh họa
	virtual void move();
	virtual void drawBody();
};