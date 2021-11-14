#pragma once


#include"CAnimal.h"
#include"Console.h"


class Bird : public CANIMAL {
	short index; // thứ tự của chim để bay. tránh trường hợp bay chồng nhau, mà tách rời ra

public:
	Bird(short, bool, short);
	~Bird();

	void setIndex(short);
	short getIndex();
};