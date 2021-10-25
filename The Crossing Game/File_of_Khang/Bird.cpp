#include "Bird.h"

Bird::Bird() {}
Bird::Bird(int toadox, int toadoy, int trangthai, int huong) {
	toadoX = toadox;
	toadoY = toadoy;
	trangThai = trangthai;
	huongDiChuyen = huong;
}

void Bird::hinhDang() {
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "bird.txt", COORD{ (short)toadoX,(short)toadoY }, (int)Color::yellow);
}


void Bird::RemoveSpace(int x, int y, int bien) {
	int size;
	if (x == bien) size = x + 4;
	else size = x + 1;
	for (int i = x; i < size; i++) {
		for (int j = y; j < y + 3; j++) {
			gotoXY(i, j);
			cout << "  ";
		}
	}
}

void Bird::diChuyen() {
	if (huongDiChuyen == 0) {
		if (toadoX <= 142) {
			DiChuyen(1);
			RemoveSpace(toadoX - 1, toadoY, 143);
			hinhDang();
		}
		else {
			RemoveSpace(toadoX, toadoY, 143);
			trangThai = 0;
			toadoX = 24;
		}
	}
	else {
		if (toadoX >= 21) {
			DiChuyen(1);
			RemoveSpace(toadoX + 4, toadoY, 20);
			hinhDang();
		}
		else {
			RemoveSpace(toadoX, toadoY, 20);
			trangThai = 0;
			toadoX = 136;
		}
	}
}

int Bird::getToaDoX() {
	return toadoX;
}