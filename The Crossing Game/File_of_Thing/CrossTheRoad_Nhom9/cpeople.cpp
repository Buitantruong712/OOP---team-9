#include"CPeople.h"


CPEOPLE::CPEOPLE() {
	X = 0;
	Y = 0;
	setTrueCoordinates();
	sprite = "player/people.txt";
	max_hearts = 5;
	hearts = max_hearts;

	vulnerable = true;

	vul_timer = 45;
	vul_running_timer = vul_timer;
}

CPEOPLE::~CPEOPLE() {}

/// 
/// - - - - - - - - - - - - SETTER VÀ GETTER - - - - - - - - - - - - 
/// 
void CPEOPLE::setCoordinates(short x, short y) {
	X = x;
	Y = y;
	setTrueCoordinates();
}


void CPEOPLE::setTrueCoordinates() {
	trueX = 2 + TILE_X * X + 5;
	trueY = 2 + TILE_Y * Y;
}

void CPEOPLE::setHearts(short value) {
	hearts = value;
}

void CPEOPLE::setMaxHearts(short value) {
	max_hearts = value;
}

short CPEOPLE::getX() {
	return X;
}

short CPEOPLE::getY() {
	return Y;
}

short CPEOPLE::getHearts() {
	return hearts;
}

short CPEOPLE::getMaxHearts() {
	return max_hearts;
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


void CPEOPLE::Control(char& get_input) {
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
		get_input = press;
	}
}


/// 
/// - - - - - - - - - - - - Vẽ - - - - - - - - - - - - 
/// 
void CPEOPLE::drawBody() {
	Console::drawFromFile(
		sprite,
		COORD{ trueX, trueY },
		(int)Color::blue
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
void CPEOPLE::resetHearts() {
	hearts = max_hearts;
}

void CPEOPLE::runInvulnerableTime() {
	Console::gotoXY(30, 1);
	if (vulnerable == false) {
		if (vul_running_timer-- == 0) {
			vulnerable = true;
			vul_running_timer = vul_timer;
			drawBody();
		}
	}
}

void CPEOPLE::resetPosition() {
	// 1) Xoá hình ở toạ độ cũ
	Console::removeSpace((short)trueX, (short)trueY);

	// 2) Chỉnh toạ độ
	setCoordinates(12, 6);

	// 3) Vẽ ngay toạ độ mới
	drawBody();
}


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
					(Y == i.getY())				// Người chơi ở hàng cùng với con chim
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
	if (Y == 0)
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
//	Console::drawFromFile("people.txt", COORD{ 80, 33 }, (int)Color::blue);
//}

//void CPEOPLE::drawLevel(int level) {
//	if (level == 1)  Console::drawFromFile("lv1.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 2) Console::drawFromFile("lv2.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 3) Console::drawFromFile("lv3.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 4) Console::drawFromFile("lv4.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 5) Console::drawFromFile("lv5.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 6) Console::drawFromFile("lv6.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 7) Console::drawFromFile("lv7.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 8) Console::drawFromFile("lv8.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 9) Console::drawFromFile("lv9.txt", COORD{ 116, 4 }, (int)Color::blue);
//	else if (level == 10) Console::drawFromFile("lv10.txt", COORD{ 116, 4 }, (int)Color::blue);
//}

bool CPEOPLE::isDead() {
	return hearts == 0;
}


void CPEOPLE::gameOver() {
	Sleep(300);

	Console::drawFromFile(
		"menu/GameOverTitle.txt",
		COORD{29, 15},
		(int)Color::dark_magneta
	);

	Sleep(300);

	Console::drawFromFile(
		"menu/GameOverTitle.txt",
		COORD{29, 15},
		(int)Color::magneta
	);

	Sleep(1000);

	Console::gotoXY(54, 22);
	std::cout << "Press anything to continue";
	_getch();
}
