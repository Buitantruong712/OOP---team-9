#include "CBird.h"

CBIRD::CBIRD() : CANIMAL() {
    Y = mY * TILE_Y + (short)Border::TOP + 1;
}

CBIRD::CBIRD(short mY, bool direction) {
    this->mY = mY;
    Y = mY * TILE_Y + (short)Border::TOP + 1;
    this->direction = direction;
}

CBIRD::~CBIRD() {

}

void CBIRD::drawBody() {
	if (direction)
		Console::drawFromFile("Mobs/Bird left.txt", COORD{ X,Y }, (int)Color::MAGENTA);
	else
		Console::drawFromFile("Mobs/Bird right.txt", COORD{ X,Y }, (int)Color::MAGENTA);
}

void CBIRD::tell() {
    if (sound) {
        PlaySound(L"Sound/Bird.wav", NULL, SND_FILENAME);
    }
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
            X--;
            drawBody();
        }
        else {
            Console::removeSpace(X, Y);
            X = (short)Border::RIGHT;
        }
    }
}
