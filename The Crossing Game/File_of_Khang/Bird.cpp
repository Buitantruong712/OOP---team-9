#include "Bird.h"

Bird::Bird() {}
Bird::Bird(int toadox, int toadoy, int trangthai, int huong) {
	coordX = toadox;
	coordY = toadoy;
	state = trangthai;
	direct = huong;
}

void Bird::body() {
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "bird.txt", COORD{ (short)coordX,(short)coordY }, (int)Color::yellow);
}

void Bird::RemoveSpace(int x, int y, int bien) {
	int size;
	if (x == bien) size = x + 4;
	else size = x + 1;
	for (int i = x; i < size; i++) {
		for (int j = y; j < y + 3; j++) {
			Console::gotoXY(i, j);
			cout << "  ";
		}
	}
}

void Bird::move() {
	if (direct == 0) {
		if (coordX <= 142) {
			cMove(1);
			RemoveSpace(coordX - 1, coordY, 143);
			body();
		}
		else {
			RemoveSpace(coordX, coordY, 143);
			state = 0;
			coordX = 24;
		}
	}
	else {
		if (coordX >= 21) {
			cMove(1);
			RemoveSpace(coordX + 4, coordY, 20);
			body();
		}
		else {
			RemoveSpace(coordX, coordY, 20);
			state = 0;
			coordX = 136;
		}
	}
}