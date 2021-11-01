#pragma once
#include"CAnimal.h"
#include"Console.h"
class Bird :public CANIMAL {
public:
	Bird();
	Bird(int, int, int, int);

	void body();
	void move();
	void RemoveSpace(int, int,int);
};