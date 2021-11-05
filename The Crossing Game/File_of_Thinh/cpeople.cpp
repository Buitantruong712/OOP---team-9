#include"CPeople.h"


CPEOPLE::CPEOPLE() {
	X = 0;
	Y = 0;
	setTrueCoordinates();
	sprite = "player/people.txt";
	max_hearts = 5;
	hearts = max_hearts;

	vulnerable = true;

	vul_timer = 15;
	vul_running_timer = vul_timer;
}

CPEOPLE::~CPEOPLE() {}


void CPEOPLE::setCoordinates(int x, int y) {
	X = x;
	Y = y;
	setTrueCoordinates();
}


void CPEOPLE::setTrueCoordinates() {
	trueX = 2 + TILE_X * X + 5;
	trueY = 2 + TILE_Y * Y;
}

/// 
/// - - - - - - - - - - - - THAO TÁC NHẬP PHÍM - - - - - - - - - - - - 
/// 
void CPEOPLE::Up() {
	// Nếu chạm biên trên
	if (Y == 0)
		return;

	// 1) Xoá hình ở toạ độ cũ
	Console::removeSpace((short)trueX, (short)trueY);

	// 2) Chỉnh toạ độ
	Y--;
	setTrueCoordinates();

	// 3) Vẽ ngay toạ độ mới
	drawBody();
}

void CPEOPLE::Down() {
	// Nếu chạm biên dưới
	if (Y == MAX_MASK_Y - 1)
		return;


	Console::removeSpace((short)trueX, (short)trueY);

	Y++;
	setTrueCoordinates();

	drawBody();
}

void CPEOPLE::Left() {
	// nếu chạm biên trái
	if (X == 0)
		return;


	short x = trueX, y = trueY;
	Console::removeSpace((short)trueX, (short)trueY);

	X--;
	setTrueCoordinates();

	drawBody();
}

void CPEOPLE::Right() {
	// nếu chạm biên phải
	if (X == MAX_MASK_X - 1)
		return;


	short x = trueX, y = trueY;
	Console::removeSpace((short)trueX, (short)trueY);

	X++;
	setTrueCoordinates();

	drawBody();
}


void CPEOPLE::Control(int& pause) {
	int press;
	if (_kbhit()) {
		press = toupper(_getch());
		if (press == 'D')
			Right();
		else if (press == 'A')
			Left();
		else if (press == 'W')
			Up();
		else if (press == 'S')
			Down();
		else if (press == 27) // escape for pause
			pause++;
	}
}

/// 
/// - - - - - - - - - - - - Vẽ - - - - - - - - - - - - 
/// 
void CPEOPLE::drawBody() {
	Console::drawFromFile(
		sprite,
		COORD{ trueX, trueY },
		(int)Color::lightblue
	);
}

void CPEOPLE::drawHeart(short x) {
	Console::drawFromFile(
		"player/heart.txt",
		COORD{ x, 1 },
		(int)Color::red
	);
}

void CPEOPLE::drawHeartBroken(short x) { // Trái tim hình nhỏ hơn nên không xài Console::removeSpace()
	Console::drawFromFile(
		"player/empty heart.txt",
		COORD{ x, 1 },
		(int)Color::red
	);
}

void CPEOPLE::drawHealthBar() {
	short i = 0;
	for (i; i < hearts; i++) {
		drawHeart(i * 6 + 2);
	} // vẽ tim theo số lượng tim
	for (i; i < max_hearts; i++) {
		drawHeartBroken(i * 6 + 2);
	}
}

/// 
/// - - - - - - - - - - - - THAO TÁC KHÁC - - - - - - - - - - - - 
/// 
void CPEOPLE::runInvulnerableTime() {
	Console::gotoXY(30, 1);
	if (vulnerable == false) {
		if (vul_running_timer-- == 0) {
			vulnerable = true;
			vul_running_timer = vul_timer;
		}
	}
}

//void CPEOPLE::pauseGame(int& pause, int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
//
//	// Vẽ cái khung
//	Console::gotoXY(153, 5);
//	cout << " (SPACE)RESUME";
//	Console::gotoXY(153, 7);
//	cout << " (S)SAVE GAME";
//	Console::gotoXY(153, 9);
//	cout << " (L)LOAD GAME";
//	Console::gotoXY(153, 11);
//	cout << "(B)BACK TO MENU";
//	Console::gotoXY(153, 13);
//	cout << "    (E)EXIT";
//
//	// Thao tác nhấn
//	int press; // Khi dừng game, không cần kbhit()
//	while (pause) {
//		press = toupper(_getch());
//		if (press == 32) pause--;
//		else if (press == 'S')	saveGame(level, speed, time, bir1, bir2, bir3, bir4, bir5);
//		else if (press == 'L') {
//			loadGame(level, speed, time, bir1, bir2, bir3, bir4, bir5);
//			break;
//		}
//		else if (press == 'B') {
//			// back to menu
//		}
//		else if (press == 'E') {
//			// exit
//		}
//	}
//	// Xoá cái khung
//	Console::gotoXY(153, 5);	cout << string(15, ' ');
//	Console::gotoXY(153, 7);	cout << string(15, ' ');
//	Console::gotoXY(153, 9);	cout << string(15, ' ');
//	Console::gotoXY(153, 11);	cout << string(15, ' ');
//	Console::gotoXY(153, 13);	cout << string(15, ' ');
//}
//
//void CPEOPLE::saveGame(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
//	string fileName;
//	Console::gotoXY(150, 17);
//	cout << "File name: ";
//	getline(cin, fileName);
//	ofstream out;
//	out.open("SaveGame/" + fileName + ".txt");
//	out << trueX << " " << trueY << endl;
//	out << level << " " << speed << " " << time << endl;
//	out << bir1.size() << endl;
//	for (auto& i : bir1)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
//	for (auto& i : bir2)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
//	for (auto& i : bir3)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
//	for (auto& i : bir4)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
//	for (auto& i : bir5)	out << i.getCoordX() << " " << i.getCoordY() << " " << i.getState() << " " << i.getDirect() << endl;
//}
//
//
//void CPEOPLE::loadGame(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
//	Console::gotoXY(151, 17);
//	string fileName;
//	cout << "Enter file : ";
//	getline(cin, fileName);
//	system("cls");
//	bir1.clear();
//	bir2.clear();
//	bir3.clear();
//	bir4.clear();
//	bir5.clear();
//
//
//	ifstream in;
//	in.open("SaveGame/" + fileName + ".txt");
//	in >> trueX;
//	in >> trueY;
//	in >> level;
//	in >> speed;
//	in >> time;
//	int tmp;
//	in >> tmp;
//	for (int j = 0; j < tmp; j++) {
//		int x, y, state, direction;
//		in >> x;
//		in >> y;
//		in >> state;
//		in >> direction;
//		Bird b(x, y, state, direction);
//		bir1.push_back(b);
//	}
//	for (int j = 0; j < tmp; j++) {
//		int x, y, state, direction;
//		in >> x;
//		in >> y;
//		in >> state;
//		in >> direction;
//		Bird b(x, y, state, direction);
//		bir2.push_back(b);
//	}
//	for (int j = 0; j < tmp; j++) {
//		int x, y, state, direction;
//		in >> x;
//		in >> y;
//		in >> state;
//		in >> direction;
//		Bird b(x, y, state, direction);
//		bir3.push_back(b);
//	}
//	for (int j = 0; j < tmp; j++) {
//		int x, y, state, direction;
//		in >> x;
//		in >> y;
//		in >> state;
//		in >> direction;
//		Bird b(x, y, state, direction);
//		bir4.push_back(b);
//	}
//	for (int j = 0; j < tmp; j++) {
//		int x, y, state, direction;
//		in >> x;
//		in >> y;
//		in >> state;
//		in >> direction;
//		Bird b(x, y, state, direction);
//		bir5.push_back(b);
//	}
//
//	Console::drawGameBot();
//	drawLevel(level);
//	Console::drawFromFile("people.txt", COORD{ short(trueX),short(trueY) }, (int)Color::lightblue);
//}
//
////bool CPEOPLE::isImpact(const CVEHICLE*&);

bool CPEOPLE::impact(std::vector<Bird> c) {
	if (vulnerable) {
		// Tạo một điểm ở bên trái và bên phải để kiểm tra va chạm
		short rightTrueX = trueX + 4; // bên phải = bên trái + 4
		short l = 0;

		// Xét từng vùng collision
		for (auto& i : c) {
			if (i.getDirection() == false) {
				if (										// Độ dài theo chiều ngang: người chơi + con chim (5 ký tự)
					((trueX <= i.getTrueX() + 4 + 1) and (trueX >= i.getTrueX())) and			// Kiểm tra bên trái người chơi
					((rightTrueX <= i.getTrueX() + 4 + 1) and (rightTrueX >= i.getTrueX() - 1)) and	// Kiểm tra bên phải người chơi
					(Y == i.getVirtualY())				// Người chơi ở hàng cùng với con chim
					) {
					hearts--;		// Va chạm với chim sẽ làm người chơi mất 1 mạng
					vulnerable = false;		// Và người chơi sẽ tránh va chạm trong 1 thời gian ngắn
					return true;
				}
			}
		}
	}
	return false;
}

bool CPEOPLE::isFinish() {
	if (trueY == 0)
		return true;
	return false;
}


//void CPEOPLE::upLevel(int& level, int& speed, int& time, vector<Bird>& bir1, vector<Bird>& bir2, vector<Bird>& bir3, vector<Bird>& bir4, vector<Bird>& bir5) {
//	// up level
//	Console::removeSpace(142, 3);
//	level++;
//	drawLevel(level);
//	// tăng độ khó
//	speed--;
//	if (speed < 20) speed = 20;
//	time -= 2;
//	if (time < 15) time = 15;
//	bir1.push_back(Bird(20, 9, 0, 0));
//	bir2.push_back(Bird(138, 14, 0, 1));
//	bir3.push_back(Bird(20, 19, 0, 0));
//	bir4.push_back(Bird(138, 24, 0, 1));
//	bir5.push_back(Bird(20, 29, 0, 0));
//
//	// set lại tọa độ người để chơi tiếp
//	setCoordinates(6, 12);
//	Console::drawFromFile("people.txt", COORD{ 80, 33 }, (int)Color::lightblue);
//}

//void CPEOPLE::drawLevel(int level) {
//	if (level == 1)  Console::drawFromFile("lv1.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 2) Console::drawFromFile("lv2.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 3) Console::drawFromFile("lv3.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 4) Console::drawFromFile("lv4.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 5) Console::drawFromFile("lv5.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 6) Console::drawFromFile("lv6.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 7) Console::drawFromFile("lv7.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 8) Console::drawFromFile("lv8.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 9) Console::drawFromFile("lv9.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//	else if (level == 10) Console::drawFromFile("lv10.txt", COORD{ 116, 4 }, (int)Color::lightblue);
//}

bool CPEOPLE::isDead() {
	return hearts == 0;
}


void CPEOPLE::gameOver() {
	if (isDead()) {
		Console::clearScreen();
		Console::gotoXY(60, 20);
		std::cout << "Game over"; // vẽ sau
	}
}
