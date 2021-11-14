#pragma once


// Lớp động vật chung


#include "Console.h"


#define LEFT_BORDER 2
#define RIGHT_BORDER 128	// do ảnh xét theo góc trên trái, không phải trung tâm,
							// nên 133 sẽ bị trừ đi 5 ký tự vì chiều dài của ảnh là 5


enum AnimalState {
	start,		// xuất hiện
	run,		// chạy trên màn hình
	finish		// qua khỏi biên
};


class CANIMAL {

protected:
	short Y;			// Bởi vì vật thể sẽ chuyển động theo chiều ngang một cách mượt mà, cho nên chỉ quan tâm đến giá trị Y
	short trueX, trueY;	// Xem CPeople
	
	short state;		// Xuất hiện màn hình. true nếu con vật ở trên màn hình, false nếu con vật đi qua biên
	bool direction;		// Hướng đi
	short speed_delay;	// Thời gian con vật ngưng rồi di tiếp // trái nghĩa với tốc độ
	short running_delay;// Chạy đến khi bằng 0, thì mới dịch chuyển

	short timer;		// Thời gian để con vật đứng im. Khi hết thời gian, con vật sẽ di chuyển
	short running_timer;// Chạy đến khi bằng 0, thì sẽ chạy một hàm nào đó

	std::string sprite{};

public:
	CANIMAL();
	~CANIMAL();

	void setTrueX(short);
	void setY(short);
	void setTrueCoordinates();

	void drawBody();

	void cMove();	// Di chuyển con vật // Hàm chính
					// Tham số là tốc độ di chuyển của con vật
	void setSpeed(short);
	short getSpeed();

	void setState(short);
	short getState();

	void setDirection(short);
	short getDirection();

	void setTimer(short);
	void setRunningTimer(short);
	short getTimer();
	short getRunningTimer();

	short getTrueX();	// Chọn giá trị X vì không có đơn vị Y
	short getY();		// Chọn đơn vị Y vì giá trị Y thực không có giá trị (+ làm code khó hiểu hơn)
};
