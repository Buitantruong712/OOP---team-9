#include"Snail.h"

CSNAIL::CSNAIL() :CANIMAL() {
    Y = mY * TILE_Y + (short)Border::TOP + 1;
}

CSNAIL::CSNAIL(short posY, bool di) {
    mY = posY;
    Y = mY * TILE_Y + (short)Border::TOP;
    direction = di;
}

CSNAIL::~CSNAIL() {

}

void CSNAIL::drawBody() {
    if (direction)
        Console::drawFromFile("Mobs/Snail left.txt", COORD{ X,Y }, (int)Color::LIGHT_YELLOW);
    else
        Console::drawFromFile("Mobs/Snail right.txt", COORD{ X,Y }, (int)Color::LIGHT_YELLOW);
}

void CSNAIL::move() {
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