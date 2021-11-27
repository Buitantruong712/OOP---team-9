#include "CPeople.h"

/// 
/// - - - - - - - - - - - - CONSTRUCTOR - DESTRUCTOR - - - - - - - - - - - - 
/// 
CPEOPLE::CPEOPLE() {
	mX = MAX_MASK_X / 2;
	mY = MAX_MASK_Y;
	setXY();
	hearts = maxHearts;
}

CPEOPLE::~CPEOPLE() {

}

// Khởi tạo đối tượng
void CPEOPLE::initPeople() {
	resetHearts();
	resetPosition();
	drawHealthBar();
}

/// 
/// - - - - - - - - - - - - SETTER- - - - - - - - - - - - 
/// 

// Cập nhật tọa độ theo ô trong khung game
void CPEOPLE::setCoordinates(short x, short y) {
	mX = x;
	mY = y;
	setXY();
}

// Cập nhật tọa độ thực trên console
void CPEOPLE::setXY() {
	X = mX * TILE_X + (short)Border::LEFT;
	Y = mY * TILE_Y + (short)Border::TOP + 1;
}

void CPEOPLE::setHeart(short h) {
	if (h < 0)
		h = 0;
	if (h > maxHearts)
		h = maxHearts;
	hearts = h;
}

/// 
/// - - - - - - - - - - - - THAO TÁC NHẬP PHÍM - - - - - - - - - - - - 
/// 

void CPEOPLE::Up() {
	if (mY == 1) {						// Nếu chạm biên trên thì đến đích -> trở về vị trí ban đầu
		mY--;
		Console::removeSpace(X, Y);		// Xoá hình ở vị trí cũ
		return;
	}
		

	Console::removeSpace(X, Y);			// Xoá hình ở vị trí cũ
	mY--;								// Chỉnh vị trí mới
	setXY();
	drawBody();							// Vẽ hình ở vị trí mới
}

void CPEOPLE::Down() {
	if (mY == MAX_MASK_Y)				// Nếu chạm biên dưới thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X, Y);
	mY++;					
	setXY();
	drawBody();				
}

void CPEOPLE::Left() {
	if (mX == 0)						// Nếu chạm biên trái thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X , Y);
	mX--;					
	setXY();
	drawBody();				
}

void CPEOPLE::Right() {
	if (mX == MAX_MASK_X)				// Nếu chạm biên phải thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X, Y);
	mX++;
	setXY();
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
/// - - - - - - - - - - - - VẼ - - - - - - - - - - - - 
/// 

// Người chơi
void CPEOPLE::drawBody() {
	Console::drawFromFile(sprite, COORD{ X, Y }, (int)Color::LIGHT_BLUE);
}

// Mạng sống còn lại của người chơi
void CPEOPLE::drawHeart(short x, short y) {
	Console::drawFromFile("Player/Heart.txt", COORD{ x,y }, (int)Color::LIGHT_RED);
}

// Mạng sống đã mất của người chơi
void CPEOPLE::drawHeartBroken(short x, short y) {
	Console::drawFromFile("Player/Empty heart.txt", COORD{ x,y }, (int)Color::LIGHT_RED);
}

// Thanh mạng sống
void CPEOPLE::drawHealthBar() {
	short x = 1;
	short y = 1;
	short i = 0;
	for (i; i < hearts; i++) {
		drawHeart(x, y);
		x += 6; // Bề ngang 1 trái tim
	} // vẽ tim còn
	for (i; i < maxHearts; i++) {
		drawHeartBroken(x, y);
		x += 6;
	} // vẽ tim mất
}

// Game over -> khi kết thúc trò chơi
void CPEOPLE::gameOver() {
	COORD pos{ Console::getMidHoritonal() - 30,Console::getMidVertical() - 5};
	Sleep(300);
	Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::MAGENTA);
	Sleep(300);
	Console::drawFromFile("Menu/GameOverTitle.txt", pos, (int)Color::LIGHT_MAGENTA);
	Sleep(1000);
	Console::gotoXY(pos.X + 15, pos.Y + 7);
	cout << "Press anything to continue";
	_getch();
}

/// 
/// - - - - - - - - - - - - RESET - - - - - - - - - - - - 
/// 

// Reset mạng sống
void CPEOPLE::resetHearts() {
	hearts = maxHearts;
}

// Reset vị trí
void CPEOPLE::resetPosition() {
	Console::removeSpace(X, Y);					// Xóa hình ở vị trí cũ
	setCoordinates(MAX_MASK_X / 2, MAX_MASK_Y); // Vị trí mới -> vị trí chính giữa của hàng cuối
	drawBody();									// Vẽ người ở vị trí mới
}	

/// 
/// - - - - - - - - - - - - CHECK TRẠNG THÁI - - - - - - - - - - - - 
/// 

// Hoàn thành vòng chơi
bool CPEOPLE::isFinish() {
	return (mY == 0);
}

// Hết mạng sống -> Thua
bool CPEOPLE::isDead() {
	return (hearts == 0);
}

// Kiểm tra va chạm với xe
bool CPEOPLE::isImpact(const CVEHICLE* &v, int num) {
	short rightX = X + TILE_X - 1;
	if (mY == v->getmY()) {
		for (int i = 0; i < num; i++) {
			if (v->getDirection())
				if (X <= v[i].getX() + TILE_X_CAR - 1 && rightX >= v[i].getX())
					return true;
		}
	}
	return false;
}

// Kiểm tra va chạm với thú
bool CPEOPLE::isImpact(const CANIMAL*& v, int num) {
	short rightX = X + TILE_X - 1;
	if (mY == v->getmY()) {
		for (int i = 0; i < num; i++) {
			if (v->getDirection())
				if (X <= v[i].getX() + TILE_X - 1 && rightX >= v[i].getX())
					return true;
		}
	}
	return false;
}


