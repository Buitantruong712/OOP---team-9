#ifndef _CVEHICLE_H
#define _CVEHICLE_H

#include "Console.h"

class CVEHICLE{
protected:
	short mY;
	short X, Y;										// Tọa độ thực trên console
	static int speed;
	bool direction = true;							// Hướng đi (true: trái -> phải, false: phải -> trái)
public:
	CVEHICLE();
	~CVEHICLE();

	// Setter
	void setmY(short row) { mY = row; Y = mY * TILE_Y + (short)Border::TOP; };
	void setX(short x) { X = x; };
	void setDirection(bool d) { direction = d; };

	// Getter
	virtual bool getDirection() const { return direction; };
	virtual short getX() const { return X; };
	virtual short getY() const { return Y; };
	virtual short getmY() const { return mY; };

	// Minh họa
	virtual void drawBody() = 0;					// Hình động vật
	//virtual void tell() = 0;						// Tiếng kêu của con vật
	virtual void move() = 0;						// Di chuyển con vật
};

#endif