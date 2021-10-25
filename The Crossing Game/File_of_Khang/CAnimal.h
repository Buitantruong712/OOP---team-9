#pragma once
#include"Console.h"

class CANIMAL
{
protected:
	int toadoX, toadoY;
	int trangThai;
	int huongDiChuyen;

public:
	CANIMAL();
	void DiChuyen(int);
	int getTrangThai();
	void setTrangThai(int);
	int getToaDoX();
	int getToaDoY();
	int getHuong();
	~CANIMAL();

};

