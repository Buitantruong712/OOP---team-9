#include"CPeople.h"


CPEOPLE::CPEOPLE() {}

void CPEOPLE::setToado(int a, int b) {
	mX = a;
	mY = b;
}

void CPEOPLE::Up(int sizeY, int tuongTren) {
	if (mY > tuongTren) {
		mY -= sizeY;
		gotoXY(mX, mY);
		short x = mX, y = mY;
		Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Graphics::RemoveSpace(x + 1, y + sizeY);
	}
}
void CPEOPLE::Left(int sizeX, int tuongTrai) {
	if (mX > tuongTrai) {
		mX -= sizeX;
		gotoXY(mX, mY);
		short x = mX, y = mY;
		Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Graphics::RemoveSpace(x + sizeX + 2, y);
	}
}

void CPEOPLE::Right(int sizeX, int tuongPhai) {
	if (mX < tuongPhai) {
		mX += sizeX;
		gotoXY(mX, mY);
		short x = mX, y = mY;
		Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Graphics::RemoveSpace(x - sizeX, y);
	}

}
void CPEOPLE::Down(int sizeY, int tuongDuoi) {
	if (mY < tuongDuoi) {
		mY += sizeY;
		gotoXY(mX, mY);
		short x = mX, y = mY;
		Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Graphics::RemoveSpace(x + 1, y - sizeY);
	}

}

void CPEOPLE::Control(int&_COMMAND) {
	if (_kbhit()) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 'D') Right(5, 140);
		else if (_COMMAND == 'A')	Left(5, 20);
		else if (_COMMAND == 'W')	Up(5, 4);
		else if (_COMMAND == 'S') 	Down(5, 33);
	}
}
//bool CPEOPLE::isImpact(const CVEHICLE*&);
bool CPEOPLE::isImpact(vector<Bird> c) {
	for (auto& i : c) {
		if (i.getHuong() == 0) {
			if (mX + 2 >= i.getToaDoX() - 3 && mX <= i.getToaDoX() + 4 && mY == i.getToaDoY() - 1) return true;
		}
		else {
			if (mX + 2 >= i.getToaDoX() - 2 && mX <= i.getToaDoX() + 5 && mY == i.getToaDoY() - 1) return true;
		}

	}
	return false;
}
bool CPEOPLE::isFinish() {
	if (mY == 3) return true;
	return false;
}

void CPEOPLE::upLevel(int&level,int &speed,int &time,vector<Bird>&bir1, vector<Bird>&bir2, vector<Bird>&bir3, vector<Bird>&bir4, vector<Bird>&bir5) {
	// up level
	Graphics::RemoveSpace(142, 3);
	level++;
	if (level == 1)  Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv1.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 2) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv2.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 3) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv3.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 4) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv4.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 5) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv5.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 6) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv6.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 7) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv7.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 8) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv8.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 9) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv9.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 10) Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "lv10.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	
	// tăng độ khó
	speed--;
	if (speed < 20) speed = 20;
	time -= 2;
	if (time < 15) time = 15;
	bir1.push_back(Bird(20, 9, 0, 0));
	bir2.push_back(Bird(138, 14, 0, 1));
	bir3.push_back(Bird(20, 19, 0, 0));
	bir4.push_back(Bird(138, 24, 0, 1));
	bir5.push_back(Bird(20, 29, 0, 0));

	// set lại tọa độ người để chơi tiếp
	setToado(80, 33);
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ 80, 33 }, (int)Color::lightblue);
}


void CPEOPLE::isDead(int& _COMMAND,int& checkTF) {
	system("cls");

	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "YouLoss.txt", COORD{ 55, 15 }, (int)Color::red);
	while (1) {
		if (_kbhit()) {
			_COMMAND = toupper(_getch());
			if (_COMMAND == 'P') break;
			else if (_COMMAND == 'M') {
				checkTF = 0;
				break;
			}
		}
	}
}

