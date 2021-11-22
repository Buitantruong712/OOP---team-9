#ifndef _VEHICLE_
#define _VEHICLE_


// Lớp xe cộ


#include "console.h"


enum class VehicleState {
	stop,		// Dừng đèn đỏ
	start,		// xuất hiện
	run,		// chạy trên màn hình
	finish		// qua khỏi biên
};


class CVEHICLE {

protected:
	short Y;			// Xem CAniaml
	short trueX, trueY;

	VehicleState state;
	bool direction;
	short speed_delay;
	short running_delay;

	short timer;
	short running_timer;

	std::string sprite{};

//public:
//	static const short width = 4;
//	static const short height = 1;

public:
	CVEHICLE();
	//CVEHICLE(short, short, short);
	//CVEHICLE(const CVEHICLE&);
	~CVEHICLE();

	void setTrueX(short);
	void setY(short);
	void setTrueCoordinates();

	void drawBody();

	void cMove();	// Di chuyển con vật // Hàm chính
					// Tham số là tốc độ di chuyển của con vật
	void setSpeed(short);
	short getSpeed();

	void setState(VehicleState);
	VehicleState getState();

	void setDirection(short);
	short getDirection();

	void setTimer(short);
	void setRunningTimer(short);
	short getTimer();
	short getRunningTimer();

	short getTrueX();	// Chọn giá trị X vì không có đơn vị Y
	short getY();		// Chọn đơn vị Y vì giá trị Y thực không có giá trị (+ làm code khó hiểu hơn)
};


//class Truck : public CVEHICLE {
//	//int X, Y;
//	//int Speed;
//
//private:
//	short index;
//
////protected:
////	int huong = 1;
//
//public:
//	Truck();
//	Truck(int, int, int);
//	Truck(const Truck&);
//	void setSpeed(int);
//
//	virtual void Move();
//	void deleteObj(int, int);
//	void draw(int, int);
//	void run(int, int); //ham 1 doi tuong chay
//	void Lane(int, int, int);
//
//};


class Car : public CVEHICLE {

private:
	short index;

//protected:
//	int huong = 0;

public:
	Car(short, bool, short);

	void setIndex(short);
	short getIndex();

	//void setSpeed(int);

	//void deleteObj(int, int);
	//virtual void Move();
	//void draw(int, int);
	//void run(int, int); //ham 1 doi tuong chay
	//void Lane(int, int, int);
};


#endif