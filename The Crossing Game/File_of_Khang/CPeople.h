#pragma once
#include"Console.h"
#include"CAnimal.h"
#include"Bird.h"
#include<vector>
class CPEOPLE {
	int mX, mY;
	bool mState; //Trạng thái sống chết
public:
	CPEOPLE();
	void setToado(int, int);
	void Up(int,int);
	void Left(int,int);
	void Right(int,int);
	void Down(int,int);
	void Control(int&);
	//bool isImpact(const CVEHICLE*&);
	bool isImpact(vector<Bird> a);
	bool isFinish();
	void upLevel(int&, int&, int&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&, vector<Bird>&);
	void isDead(int&,int&);
};
