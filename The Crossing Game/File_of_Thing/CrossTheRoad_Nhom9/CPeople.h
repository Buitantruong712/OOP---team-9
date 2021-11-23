#pragma once


#include "Console.h"
#include "CAnimal.h"
#include "CVehicle.h"


class CPEOPLE {

private:
	short X, Y;			// Toạ độ theo đơn vị ô. Trong đây: 25 x 7
	short trueX, trueY;	// Toạ độ thực trên console. Trong đây: 135 x 33 (Hoặc 125 x 28). Mỗi ô chiếm 5 x 4

	std::string sprite{}; // Tên file (Ở đây hiểu theo nghĩa là ảnh của class này)
	short max_hearts;	// Mạng sống của người chơi
	short hearts;

	bool vulnerable;	// Tránh trường hợp va chạm cùng lúc, gây mất 2 mạng
	short vul_timer;	// Rút thời gian
	short vul_running_timer;

public:
	CPEOPLE();
	~CPEOPLE();

	// Xác định toạ độ và di chuyển
	void Up();
	void Left();
	void Right();
	void Down();
	void Control(char&);		// Thao tác 4 hàm trên

	// Vẽ
	void drawBody();
	void drawHeart(short);	// mạng sống của người chơi
	void drawHeartBroken(short);
	void drawHealthBar();

	// Thao tác trong trò chơi khác
	void resetHearts();
	void runInvulnerableTime();	// Chạy nếu khi người chơi đã bị va chạm
	void resetPosition();

	//bool isImpact(const CVEHICLE*&);
	bool impact(std::vector<Bird> a);
	bool impact(std::vector<Car> a);
	bool isFinish();
	//void upLevel(int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	bool isDead();
	void gameOver();

	// Hàm setter
	void setCoordinates(short, short);	// Ứng với X, Y
	void setTrueCoordinates();			// Ứng với trueX, trueY
	void setHearts(short);
	void setMaxHearts(short);

	// Hàm getter
	short getX();			// Lấy X
	short getY();			// Lấy Y
	short getHearts();
	short getMaxHearts();
};
