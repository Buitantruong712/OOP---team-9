#include "Bird.h"

Bird::Bird() {

}

Bird::Bird(short y, bool direction, short speed) {
	Y = y;
	setTrueCoordinates();
	setState(start);
	setDirection(direction);
	setSpeed(speed);
	setTimer(0);
	running_timer = timer;
	this->index = index;
	sprite = "mobs/bird.txt";
}

void Bird::setIndex(short value) {
	index = value;
	timer += 25 * value;
	running_timer = timer;
}

short Bird::getIndex() {
	return index;
}
