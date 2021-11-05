#include "cgame.h"


CGAME::CGAME() {
	short quantity = 5;

	Bird new_bird(3, false, 1); // Hàng 3, đi từ trái sang phải

	for (int i = 0; i < quantity; i++) {
		new_bird.setTimer(rand() % 40 + 5);
		birds.push_back(new_bird);
		birds[i].setIndex(i);
	}
	
}


void CGAME::drawGame() {
	Console::drawGameBot();
	player.setCoordinates(12, 6);
}


CGAME::~CGAME() {

}

//CPEOPLE getPeople();
//CVEHICLE * getVehicle();
std::vector <Bird> CGAME::getAnimal() {
	return birds;
}

void CGAME::resetGame() {

}

void CGAME::exitGame(HANDLE) {
	
}

void CGAME::startGame() {
	// Vẽ khung
	drawGame();
	player.drawHealthBar();

	int is_escape = 0;
	while (not is_escape and not player.isDead()) {
		// Chạy con vật
		for (auto& i : birds)
			i.cMove();

		if (player.impact(birds)) {
			player.drawHealthBar();
		}

		// Chạy người chơi
		player.runInvulnerableTime();
		player.Control(is_escape);
		if (is_escape)
			break;

		// Thời gian nghỉ
		Sleep(30);
	}

	player.gameOver();
}

void CGAME::loadGame() {
	// using std::ifstream
}

void CGAME::saveGame() {
	// using std::ofstream
}

void CGAME::pauseGame(HANDLE) {

}

void CGAME::resumeGame(HANDLE) {
	// this one is the loop function
}

void CGAME::updatePosPeople(char update) {
	
}

void CGAME::updatePosVehicle() {

}

void CGAME::updatePosAnimal() {

}
