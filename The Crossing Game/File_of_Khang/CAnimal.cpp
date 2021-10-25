#include"CAnimal.h"

CANIMAL::CANIMAL() {}

void CANIMAL::DiChuyen(int sizeOfAnimal) {
	if (huongDiChuyen == 0) {
		toadoX += sizeOfAnimal;
	}
	else {
		toadoX -= sizeOfAnimal;
	}
}

void CANIMAL::setTrangThai(int a) {	trangThai = a;}
int CANIMAL::getTrangThai() {return trangThai;}
int CANIMAL::getHuong() {return huongDiChuyen;}
int CANIMAL::getToaDoX() {return toadoX;}
int CANIMAL::getToaDoY() {return toadoY;}

CANIMAL::~CANIMAL() {}
