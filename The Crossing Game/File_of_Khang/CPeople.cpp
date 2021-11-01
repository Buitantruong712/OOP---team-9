#include"CPeople.h"


CPEOPLE::CPEOPLE() {}

void CPEOPLE::setCoordinates(int a, int b) {
	mX = a;
	mY = b;
}

void CPEOPLE::Up(int sizeY, int upperMargin) {
	if (mY > upperMargin) {
		mY -= sizeY;
		Console::gotoXY(mX, mY);
		short x = mX, y = mY;
		Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Console::removeSpace(x + 1, y + sizeY);
	}
}

void CPEOPLE::Down(int sizeY, int belowMargin) {
	if (mY < belowMargin) {
		mY += sizeY;
		Console::gotoXY(mX, mY);
		short x = mX, y = mY;
		Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Console::removeSpace(x + 1, y - sizeY);
	}
}

void CPEOPLE::Left(int sizeX, int leftMargin) {
	if (mX > leftMargin) {
		mX -= sizeX;
		Console::gotoXY(mX, mY);
		short x = mX, y = mY;
		Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Console::removeSpace(x + sizeX + 2, y);
	}
}

void CPEOPLE::Right(int sizeX, int rightMargin) {
	if (mX < rightMargin) {
		mX += sizeX;
		Console::gotoXY(mX, mY);
		short x = mX, y = mY;
		Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ x,y }, (int)Color::lightblue);
		Console::removeSpace(x - sizeX, y);
	}
}


void CPEOPLE::Control(int& p) {
	int press;
	if (_kbhit()) {
		press = toupper(_getch());
		if (press == 'D') Right(5, 140);
		else if (press == 'A')	Left(5, 20);
		else if (press == 'W')	Up(5, 4);
		else if (press == 'S') 	Down(5, 33);
		else if (press == 32)		p++;
	}
}

void CPEOPLE::pauseGame(int& pause, int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
	Console::gotoXY(153, 5);
	cout << " (SPACE)RESUME";
	Console::gotoXY(153, 7);
	cout << " (S)SAVE GAME";
	Console::gotoXY(153, 9);
	cout << " (L)LOAD GAME";
	Console::gotoXY(153, 11);
	cout << "(B)BACK TO MENU";
	Console::gotoXY(153, 13);
	cout << "    (E)EXIT";
	int press;
	while (pause) {
		if (_kbhit()) {
			press = toupper(_getch());
			if (press == 32) pause--;
			else if (press == 'S')	saveGame(level, speed, time, bir1, bir2, bir3, bir4, bir5);
			else if (press == 'L'){
				loadGame(level, speed, time, bir1, bir2, bir3, bir4, bir5);
				break;
			}
			else if (press == 'B') {
				// back to menu
			}
			else if (press == 'E') {
				// exit
			}
		}
	}
	Console::gotoXY(153, 5);
	cout << "               ";
	Console::gotoXY(153, 7);
	cout << "               ";
	Console::gotoXY(153, 9);
	cout << "               ";
	Console::gotoXY(153, 11);
	cout << "               ";
	Console::gotoXY(153, 13);
	cout << "               ";
}

void CPEOPLE::saveGame(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
	string fileName;
	Console::gotoXY(150, 17);
	cout << "File name: ";
	getline(cin, fileName);
	ofstream out;
	out.open("SaveGame/" + fileName + ".txt");
	out << mX << " " << mY << endl;
	out << level << " " << speed << " " << time << endl;
	out << bir1.size() << endl;
	for (auto& i : bir1)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
	for (auto& i : bir2)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
	for (auto& i : bir3)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
	for (auto& i : bir4)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
	for (auto& i : bir5)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
}


void CPEOPLE::loadGame(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
	Console::gotoXY(151, 17);
	string fileName;
	cout << "Enter file : ";
	getline(cin, fileName);
	system("cls");
	bir1.clear();
	bir2.clear();
	bir3.clear();
	bir4.clear();
	bir5.clear();


	ifstream in;
	in.open("SaveGame/" + fileName + ".txt");
	in >> mX;
	in >> mY;
	in >> level;
	in >> speed;
	in >> time;
	int tmp;
	in >> tmp;
	for (int j = 0; j < tmp; j++) {
		int x, y, state, direct;
		in >> x;
		in >> y;
		in >> state;
		in >> direct;
		Bird b(x, y, state, direct);
		bir1.push_back(b);
	}
	for (int j = 0; j < tmp; j++) {
		int x, y, state, direct;
		in >> x;
		in >> y;
		in >> state;
		in >> direct;
		Bird b(x, y, state, direct);
		bir2.push_back(b);
	}
	for (int j = 0; j < tmp; j++) {
		int x, y, state, direct;
		in >> x;
		in >> y;
		in >> state;
		in >> direct;
		Bird b(x, y, state, direct);
		bir3.push_back(b);
	}
	for (int j = 0; j < tmp; j++) {
		int x, y, state, direct;
		in >> x;
		in >> y;
		in >> state;
		in >> direct;
		Bird b(x, y, state, direct);
		bir4.push_back(b);
	}
	for (int j = 0; j < tmp; j++) {
		int x, y, state, direct;
		in >> x;
		in >> y;
		in >> state;
		in >> direct;
		Bird b(x, y, state, direct);
		bir5.push_back(b);
	}

	Console::drawGameBot();
	drawLevel(level);
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ short(mX),short(mY) }, (int)Color::lightblue);
}

//bool CPEOPLE::isImpact(const CVEHICLE*&);
bool CPEOPLE::isImpact(vector<Bird> c) {
	for (auto& i : c) {
		if (i.getDirect() == 0) {
			if (mX + 2 >= i.getCoordX() - 3 && mX <= i.getCoordX() + 4 && mY == i.getCoordY() - 1) return true;
		}
		else {
			if (mX + 2 >= i.getCoordX() - 2 && mX <= i.getCoordX() + 5 && mY == i.getCoordY() - 1) return true;
		}

	}
	return false;
}

bool CPEOPLE::isFinish() {
	if (mY == 3) return true;
	return false;
}


void CPEOPLE::upLevel(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
	// up level
	Console::removeSpace(142, 3);
	level++;
	drawLevel(level);
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
	setCoordinates(80, 33);
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ 80, 33 }, (int)Color::lightblue);
}

void CPEOPLE::drawLevel(int level) {
	if (level == 1)  Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv1.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 2) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv2.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 3) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv3.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 4) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv4.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 5) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv5.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 6) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv6.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 7) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv7.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 8) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv8.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 9) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv9.txt", COORD{ 116, 4 }, (int)Color::lightblue);
	else if (level == 10) Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "lv10.txt", COORD{ 116, 4 }, (int)Color::lightblue);
}

void CPEOPLE::isDead(int& checkTF) {
	system("cls");
	int press;
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "YouLoss.txt", COORD{ 55, 15 }, (int)Color::red);
	while (1) {
		if (_kbhit()) {
			press = toupper(_getch());
			if (press == 'P') break;
			else if (press == 'M') {
				checkTF = 0;
				break;
			}
		}
	}
}

