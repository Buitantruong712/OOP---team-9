#ifndef _CMONKEY_H
#define _CMONKEY_H

#include "CAnimal.h"

class CMONKEY : public CANIMAL {
public:
	CMONKEY();
	CMONKEY(short, bool);
	~CMONKEY();

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };

	// Minh họa
	virtual void move();
	virtual void drawBody();
};
#endif // !_CMONKEY_H


