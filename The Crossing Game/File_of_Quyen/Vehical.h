#include "Console.h"

class Vehical {
protected:
	int mX, mY;
	int mSpeed;
public:
	static const int width = 4;
	static const int height = 1;
public:
	Vehical();
	Vehical(int, int, int);
	Vehical(const Vehical&);
	int Get_mX();
	int Get_mY();
	int Get_mSpeed();
	virtual void Move( int);
	//virtual void deleteObj();
	~Vehical();

	void setPos(int, int);
	void setSpeed(int);
	void changeSpeed(int);
};



class Truck :public Vehical {
	//int X, Y;
	//int Speed;
protected:
	int huong = 1;
public:
	Truck();
	Truck(int, int, int);
	Truck(const Truck&);
	void setSpeed(int);
	~Truck();

	virtual void Move();
	void deleteObj(int, int);
	void draw(int,int) ;
	void run(int, int); //ham 1 doi tuong chay
	void Lane(int, int, int);

};

class Car :public Vehical {
protected:
	int huong = 0;
public:
	Car();
	Car(int, int, int);
	Car(const Car&);
	void setSpeed(int);
	~Car();

	void deleteObj(int, int);		
	virtual void Move();
	void draw(int,int) ;
	void run(int, int); //ham 1 doi tuong chay
	void Lane(int, int, int);
};