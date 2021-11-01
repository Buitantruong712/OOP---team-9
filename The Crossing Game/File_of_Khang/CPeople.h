#pragma once
#include"Console.h"
#include"CAnimal.h"
#include"Bird.h"
class CPEOPLE {
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	CPEOPLE();
	void setCoordinates(int, int);
	void Up(int, int);
	void Left(int, int);
	void Right(int, int);
	void Down(int, int);
	void Control(int&);
	void pauseGame(int&, int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	void saveGame(int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	void loadGame(int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	void drawLevel(int);
	//bool isImpact(const CVEHICLE*&);
	bool isImpact(vector<Bird> a);
	bool isFinish();
	void upLevel(int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	void isDead(int&);
};
