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
						if (!cg.pressable) MOVING = ' ';
						else MOVING = key;		// Bắt đầu tiếp
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

void MusicThread() {
	if (MUSIC)
		PlaySound(L"Music/Music1.wav", NULL, SND_FILENAME);
}

void SoundThread() {
	int currentPos = cg.getPeople()->getmY();
	if (currentPos == cg.getCar()->getmY())
		cg.getCar()->tell();
	else if (currentPos == cg.getTruck()->getmY())
		cg.getTruck()->tell();
	else if (currentPos == cg.getHelicopter()->getmY())
		cg.getHelicopter()->tell();
	else if (currentPos == cg.getBird()->getmY())
		cg.getBird()->tell();
	else if (currentPos == cg.getMonkey()->getmY())
		cg.getMonkey()->tell();
}

void SubThread() {
	short delay_running = 12;
	short delay = 12;

	thread tSound(SoundThread);

	while (cg.IS_RUNNING) {
		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING, &tSound);
		}
		MOVING = ' ';
		Sleep(10);
		delay_running--;
		if (delay_running == 0) {
			cg.runTraffic();
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
				cg.pressable = false;
				if (SOUND) {
					PlaySound(L"Sound/Accident.wav", NULL, SND_FILENAME);
				}
				cg.getPeople()->resetPosition();
				cg.pressable = true;
			}
			delay_running = delay;
		}

		//Kiểm tra đến đích 
		if (cg.getPeople()->isFinish()) {
			// Tăng level
			cg.LEVEL++;

			// Hiệu ứng chuyển level
			cg.pressable = false;

			Console::drawFromFile("Map/EmptyFrame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP + 5 }, (int)Color::LIGHT_GRAY);
			cg.drawLevel(cg.LEVEL);
			if (SOUND) {
				PlaySound(L"Sound/UpLevel.wav", NULL, SND_FILENAME);
			}
			if (cg.LEVEL < cg.MAX_LEVEL)
				cg.drawTime(cg.LEVEL);

			// Chỉnh level

			switch (cg.LEVEL) {

			case 2:
				delay = 7;
				cg.resetGame(2, 3, 1, 3, 2);
				break;

			case 3:
				cg.resetGame(2, 4, 2, 3, 2);
				break;

			case 4:
				delay = 6;
				cg.resetGame(2, 4, 3, 3, 3);
				break;

			case 5:
				delay = 5;
				cg.resetGame(3, 3, 4, 4, 3);
				break;

			case 6:
				cg.resetGame(3, 4, 4, 4, 3);
				break;

			case 7:
				delay = 4;
				cg.resetGame(4, 4, 4, 4, 4);
				break;

			case 8:
				cg.resetGame(4, 4, 4, 5, 3);
				break;

			case 9:
				delay = 3;
				cg.resetGame(4, 6, 3, 4, 3);
				break;

			case 10:
				cg.resetGame(4, 6, 3, 5, 3);
				break;

			case 11:
				delay = 2;
				cg.resetGame(4, 4, 4, 5, 4);
				break;

			case 12:
				cg.resetGame(4, 6, 4, 5, 4);
				break;

			default:
				cg.gameWinner();

				break;
			}

			delay_running = delay;
			// Đặt lại vị trí người chơi

			cg.getPeople()->resetPosition();
			
			// Và cho người chơi nhập
			cg.pressable = true;
		}
	}
	tSound.join();
}