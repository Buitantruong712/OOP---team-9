#include"CAnimal.h"

CANIMAL::CANIMAL() {}

void CANIMAL::cMove(int sizeOfAnimal) {
	if (direct == 0) coordX += sizeOfAnimal;
	else 	coordX -= sizeOfAnimal;
}

void CANIMAL::setState(int a) {	state = a;}
int CANIMAL::getState() {return state;}
int CANIMAL::getDirect() {return direct;}
int CANIMAL::getCoordX() {return coordX;}
int CANIMAL::getCoordY() {return coordY;}

CANIMAL::~CANIMAL() {}