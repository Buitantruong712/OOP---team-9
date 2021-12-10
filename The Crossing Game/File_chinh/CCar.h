#ifndef _CCAR_H
#define _CCAR_H

#include "CVehicle.h"

class CCAR : public CVEHICLE {
public:
	CCAR();
	CCAR(short, bool);
	~CCAR();

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




