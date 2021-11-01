#pragma once
#include"Console.h"

class CANIMAL
{
protected:
	int coordX, coordY;
	int state;
	int direct; 
public:
	CANIMAL();
	void cMove(int);
	int getState();
	void setState(int);
	int getCoordX();
	int getCoordY();
	int getDirect();
	~CANIMAL();

};