#ifndef _CPEOPLE_H
#define _CPEOPLE_H

#include "Console.h"
#include "CAnimal.h"
#include "CVehicle.h"

class CPEOPLE {
	short mX, mY;								// Tọa độ theo đơn vị ô
	short X, Y;									// Tọa độ thực trên console
	short hearts;								// Mạng sống còn lại (Nếu hearts = 0 thì chết)

	const string sprite = "Player/People.txt";	// File lưu hình vẽ của CPEOPLE
	const short maxHearts = 5;					// Mạng sống mặc định
public:
	CPEOPLE();
	~CPEOPLE();

	// Khởi tạo lại đối tượng
	void initPeople();

	// Cập nhật tọa độ (Setter)
	void setCoordinates(short, short);	// set tọa độ theo đơn vị ô
	void setXY();						// set tọa độ thực
	void setHeart(short);
	
	// Getter 
	int getX() { return X; };
	int getY() { return Y; };
	short getHearts() { return hearts; };

	// Cập nhật vị trí 
	void Up();
	void Down();
	void Left();
	void Right();

	// Vẽ
	void drawBody();					// Người chơi
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


