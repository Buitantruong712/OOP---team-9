#ifndef _CPEOPLE_H
#define _CPEOPLE_H

#include "Console.h"
#include "CAnimal.h"
#include "CVehicle.h"

class CPEOPLE {

	short mX, mY;							// Tọa độ theo đơn vị ô			// Giới hạn là 2 - 22 thay vì 0 - 24
	short X, Y;								// Tọa độ thực trên console
	short hearts;							// Mạng sống còn lại (Nếu hearts = 0 thì chết)
	short max_hearts;						// Mạng sống mặc định
	bool body_direction;                    // Hướng người xoay trái hoặc phải (true quay qua phải, false ngược lại)

public:
	CPEOPLE();
	~CPEOPLE();

	// Khởi tạo lại đối tượng
	void initPeople();

	// Cập nhật tọa độ (Setter)
	void setCoordinates(short, short);	// set tọa độ theo đơn vị ô
	void setXY();						// set tọa độ thực

	void subHeart();
	
	// Setter
	void setmX(short value) { mX = value, X = mX * TILE_X + (short)Border::LEFT; };
	void setmY(short value) { mY = value, Y = mY * TILE_Y + (short)Border::TOP + 1; };
	void setHearts(short value) { hearts = value; };
	void setMaxHearts(short value) { max_hearts = value; };

	// Getter 
	short getmX() { return mX; };
	short getmY() { return mY; };
	short getX() { return X; };
	short getY() { return Y; };
	short getHearts() { return hearts; };
	short getMaxHearts() { return max_hearts; };

	// Cập nhật vị trí 
	void Up();
	void Down();
	void Left();
	void Right();

	// Vẽ
	void drawBody(bool);					// Người chơi
	void drawHeart(short, short);		// Mạng sống còn lại của người chơi
	void drawHeartBroken(short, short);	// Mạng sống đã mất của người chơi	
	void drawHealthBar();				// Thanh mạng sống

	// Reset
	void resetHearts();					// Reset mạng sống
	void resetPosition();				// Reset vị trí

	// Check trạng thái
	bool isFinish();
	bool isDead();
	bool isImpact(const CVEHICLE*, int);
	bool isImpact(const CANIMAL*, int);
};
#endif 


