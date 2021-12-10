#include "CGame.h"

char MOVING;
CGAME cg;
bool THEME = 1, SOUND = 1, MUSIC = 1;

int main() {
	while (1) {
	int menuChoice = cg.runMainMenu();

		if (menuChoice == 0) {
			cg.startGame();

			int key;
			thread t1(SubThread);
				
			while (1) {
				key = toupper(_getch());

				if (!cg.getPeople()->isDead()) {
					if (key == 27) {
						cg.exitGame(&t1);
						break;
					}
					else if (key == 'P') {
						if (!cg.pauseGame(&t1)) {
							break;
						}
					}
					else if (key == 'T') {

					}
					else if (key == 'L') {

					}
					else if (cg.IS_RUNNING)
						MOVING = key;
				}
				else {	
					cg.exitGame(&t1);
					cg.gameOver();
					break;
				}
			}
		}
		else if (menuChoice == 1) {
			//Load game
		}
		else if (menuChoice == 2) {
			cg.setting();
		}
		else 
			break;
	}
	return 0;
}

void SubThread() {
	int a = 8;
	int b = 8;
	while (cg.IS_RUNNING) {

		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING);
		}
		MOVING = ' ';
		Sleep(10);
		a--;
		if (a == 1) {
			cg.updatePosVehical();
			cg.updatePosAnimal();

			// Kiểm tra va chạm
			if (cg.getPeople()->isImpact(cg.getCar(), cg.getCarSize())
				|| cg.getPeople()->isImpact(cg.getTruck(), cg.getTruckSize())
				|| cg.getPeople()->isImpact(cg.getHelicopter(), cg.getHelicopterSize())
				|| cg.getPeople()->isImpact(cg.getBird(), cg.getBirdSize())
				|| cg.getPeople()->isImpact(cg.getMonkey(), cg.getMonkeySize())
				)
			{
				cg.getPeople()->subHeart();
				cg.getPeople()->drawHealthBar();
				cg.getPeople()->resetPosition();
			}
			a = b;
		}

		//Kiểm tra đến đích 
		if (cg.getPeople()->isFinish()) {
			b--;
			cg.upLevel();
			cg.drawLevel();
			cg.getPeople()->resetPosition();
		}
	}
}