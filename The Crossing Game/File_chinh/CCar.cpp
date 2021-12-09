#include "CCar.h"

CCAR::CCAR() :CVEHICLE() {
    Y = mY * TILE_Y + (short)Border::TOP;
}

CCAR::CCAR(short posY, bool direction) {
    mY = posY;
    Y = mY * TILE_Y + (short)Border::TOP;
    this->direction = direction;
}

CCAR::~CCAR() {

}

void CCAR::drawBody() {
    if (direction)
        Console::drawFromFile("Mobs/Car left.txt", COORD{ X,Y }, (int)Color::LIGHT_GREEN);
    else
        Console::drawFromFile("Mobs/Car right.txt", COORD{ X,Y }, (int)Color::LIGHT_GREEN);
}

void CCAR::move() {
    if (direction) {
        if (X < (short)Border::RIGHT - 10) {
            Console::removeSpace(X, Y, true);
            X++;
            drawBody();
        }
        else {
            Console::removeSpace(X, Y, true);
            X = (short)Border::LEFT;
        }
    }
    else {
        if (X > (short)Border::LEFT) {
            Console::removeSpace(X, Y, true);
            X--;
            drawBody();
        }
        else {
            Console::removeSpace(X, Y, true);
            X = (short)Border::RIGHT;
        }
    }
}
