#include "CAnimal.h"


Bird::Bird(short y, bool direction, short speed_delay) {
	Y = y;
	setTrueCoordinates();
	setState(AnimalState::start);
	setDirection(direction);
	setSpeed(speed_delay);
	setTimer(0);
	running_timer = timer;
	this->index = index;
	sprite = (direction == false ? "mobs/bird_left.txt" : "mob/bird_right.txt");
}


void Bird::setIndex(short value) {
	index = value;
	timer += 200 * value;
	running_timer = timer;
}

short Bird::getIndex() {
	return index;
}
