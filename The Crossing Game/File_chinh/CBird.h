#ifndef _CBIRD_H
#define _CBIRD_H

#include "CAnimal.h"

class CBIRD : public CANIMAL {
private:
public:
	CBIRD();
	CBIRD(short, bool);
	~CBIRD();

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };
	// Minh họa
	virtual void move();
	virtual void drawBody();
};
#endif 
