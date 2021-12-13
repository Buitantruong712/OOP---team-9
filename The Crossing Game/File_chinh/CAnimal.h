#ifndef _ANIMAL_H
#define _ANIMAL_H

#include "Console.h"

class CANIMAL {

protected:
	short mY;
	short X, Y;										// Tọa độ thực trên console
	bool direction;									// Hướng bay (true: trái -> phải, false: phải -> trái)

public:
	CANIMAL();
	~CANIMAL();
	
	// Setter
	void setmY(short value) { mY = value; Y = mY * TILE_Y + (short)Border::TOP; };
	void setX(short value) { value >= 0 ? X = value : X = 0; };
	void setDirection(bool value) { direction = value; };

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };

	// Minh họa
	virtual void drawBody() = 0;					// Hình động vật
	virtual void tell() = 0;						// Tiếng kêu của con vật
	virtual void move() = 0;						// Di chuyển con vật
};

#endif