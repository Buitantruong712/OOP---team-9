#ifndef _ANIMAL_
#define _ANIMAL_


// Lớp động vật chung


#include "console.h"


enum class AnimalState {
	start,		// xuất hiện
	run,		// chạy trên màn hình
	finish		// qua khỏi biên
};


class CANIMAL {

protected:
	short Y;			// Bởi vì vật thể sẽ chuyển động theo chiều ngang một cách mượt mà, cho nên chỉ quan tâm đến giá trị Y
	short trueX, trueY;	// Xem CPeople
	
	AnimalState state;	// Tình trạng con vật (xem enum class ở trên)
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

	void setState(AnimalState);
	AnimalState getState();

	void setDirection(short);
	short getDirection();

	void setTimer(short);
	void setRunningTimer(short);
	short getTimer();
	short getRunningTimer();

	short getTrueX();	// Chọn giá trị X vì không có đơn vị Y
	short getY();		// Chọn đơn vị Y vì giá trị Y thực không có giá trị (+ làm code khó hiểu hơn)
};


// Mob mới: con chim

class Bird : public CANIMAL {

private:
	short index; // thứ tự của chim để bay. tránh trường hợp bay chồng nhau, mà tách rời ra

public:
	Bird(short, bool, short);

	void setIndex(short);
	short getIndex();
};


#endif