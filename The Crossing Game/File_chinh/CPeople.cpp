#include "CPeople.h"

/// 
/// - - - - - - - - - - - - CONSTRUCTOR - DESTRUCTOR - - - - - - - - - - - - 
/// 
CPEOPLE::CPEOPLE() {
	mX = MAX_MASK_X / 2;
	mY = MAX_MASK_Y;
	setXY();
	max_hearts = set_max_hearts;
	hearts = max_hearts;
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

void CPEOPLE::subHeart() {
	hearts--;
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
	drawBody(1);							// Vẽ hình ở vị trí mới
}

void CPEOPLE::Down() {
	if (mY == MAX_MASK_Y)				// Nếu chạm biên dưới thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X, Y);
	mY++;
	setXY();
	drawBody(0);
}

void CPEOPLE::Left() {
	if (mX == 2)						// Nếu chạm biên trái thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X, Y);
	mX--;
	setXY();
	drawBody(0);
}

void CPEOPLE::Right() {
	if (mX == MAX_MASK_X - 2)				// Nếu chạm biên phải thì không di chuyển lên được nữa
		return;

	Console::removeSpace(X, Y);
	mX++;
	setXY();
	drawBody(1);
}

/// 
/// - - - - - - - - - - - - VẼ - - - - - - - - - - - - 
/// 

// Người chơi
void CPEOPLE::drawBody(bool a) {
	body_direction = a;
	if (body_direction) Console::drawFromFile("Player/People left.txt", COORD{ X, Y }, (int)Color::BLUE);
	else Console::drawFromFile("Player/People right.txt", COORD{ X, Y }, (int)Color::BLUE);
}

// Mạng sống còn lại của người chơi
void CPEOPLE::drawHeart(short x, short y) {
	Console::drawFromFile("Player/Heart.txt", COORD{ x,y }, (int)Color::DARK_RED);
}

// Mạng sống đã mất của người chơi
void CPEOPLE::drawHeartBroken(short x, short y) {
	Console::drawFromFile("Player/Empty heart.txt", COORD{ x,y }, (int)Color::DARK_RED);
}

// Thanh mạng sống
void CPEOPLE::drawHealthBar() {
	short x = (short)Border::LEFT + 5;
	short y = 2;
	short i = 0;
	for (i; i < hearts; i++) {
		drawHeart(x, y);
		x += 6; // Bề ngang 1 trái tim
	} // vẽ tim còn
	for (i; i < max_hearts; i++) {
		drawHeartBroken(x, y);
		x += 6;
	} // vẽ tim mất
}

/// 
/// - - - - - - - - - - - - RESET - - - - - - - - - - - - 
/// 

// Reset mạng sống
void CPEOPLE::resetHearts() {
	max_hearts = set_max_hearts;
	hearts = max_hearts;
}

// Reset vị trí
void CPEOPLE::resetPosition() {
	Console::removeSpace(X, Y);					// Xóa hình ở vị trí cũ
	setCoordinates(MAX_MASK_X / 2, MAX_MASK_Y); // Vị trí mới -> vị trí chính giữa của hàng cuối
	drawBody(1);									// Vẽ người ở vị trí mới
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
bool CPEOPLE::isImpact(const CVEHICLE* v, int num) {
	short rightX = X + TILE_X - 1;
	if (mY == v->getmY()) {
		for (int i = 0; i < num; i++) {
			if (X <= v[i].getX() + TILE_X_CAR - 1 && rightX >= v[i].getX())
				return true;
		}
	}
	return false;
}

// Kiểm tra va chạm với thú
bool CPEOPLE::isImpact(const CANIMAL* v, int num) {
	short rightX = X + TILE_X - 1;
	if (mY == v->getmY()) {
		for (int i = 0; i < num; i++) {
			if (X <= v[i].getX() + TILE_X - 1 && rightX >= v[i].getX())
				return true;
		}
	}
	return false;
}


