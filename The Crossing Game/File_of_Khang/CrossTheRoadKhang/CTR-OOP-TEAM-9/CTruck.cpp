#include "CTruck.h"

CTRUCK::CTRUCK() : CVEHICLE() {
    Y = mY * TILE_Y + (short)Border::TOP;
}

CTRUCK::CTRUCK(short posY, bool direction) {
    mY = posY;
    Y = mY * TILE_Y + (short)Border::TOP;
    this->direction = direction;
}

CTRUCK::~CTRUCK() {

}

void CTRUCK::drawBody() {
    if (direction)
        Console::drawFromFile("Mobs/Truck left.txt", COORD{ X,Y }, (int)Color::YELLOW);
    else
        Console::drawFromFile("Mobs/Truck right.txt", COORD{ X,Y }, (int)Color::YELLOW);
}

void CTRUCK::move() {
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