#include "CBird.h"

CBIRD::CBIRD() :CANIMAL() {
    Y = mY * TILE_Y + (short)Border::TOP + 1;
}

CBIRD::CBIRD(short posY, bool di) {
    mY = posY;
    Y = mY * TILE_Y + (short)Border::TOP;
    direction = di;
}

CBIRD::~CBIRD() {

}

void CBIRD::drawBody() {
	if (direction)
		Console::drawFromFile("Mobs/Bird left.txt", COORD{ X,Y }, (int)Color::LIGHT_YELLOW);
	else
		Console::drawFromFile("Mobs/Bird right.txt", COORD{ X,Y }, (int)Color::LIGHT_YELLOW);
}

void CBIRD::move() {
    if (direction) {
        if (X < (short)Border::RIGHT) {
            Console::removeSpace(X, Y);
            X++;
            drawBody();
        }
        else {
            Console::removeSpace(X, Y);
            X = (short)Border::LEFT;
        }
    }
    else {
        if (X > (short)Border::LEFT) {
            Console::removeSpace(X, Y);
            X++;
            drawBody();
        }
        else {
            Console::removeSpace(X, Y);
            X = (short)Border::RIGHT;
        }
    }
}
