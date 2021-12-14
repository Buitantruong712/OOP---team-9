#include "CGame.h"

char MOVING;
CGAME cg;
bool THEME = 1, SOUND = 1;

int main() {
	thread sound(SoundThread);
	while (1) {
		int menuChoice = cg.runMainMenu(&sound);

		if (menuChoice == 0 || menuChoice == 1) {
			if (menuChoice == 0)
				cg.startGame();
			else {
				cg.loadGame(); // Nếu có load, is_running = true, nếu false, vòng lặp dưới sẽ không được chạy
				if (cg.IS_RUNNING == false) {	// Nếu không chọn load game thì không cho chạy đến thread
					continue;
				}
			}

			int key;
			thread t1(SubThread);
			while (1) {
				if (!cg.getPeople()->isDead()) {
					key = toupper(_getch());
					if (key == 27) {
						cg.exitGame(&t1);
						break;
					}
					else if (key == 'P') {
						if (!cg.pauseGame(&t1)) {
							break;
						}
					}
					else if (key == 'L') cg.saveGame(&t1);			// Lưu game lập tức
					else if (key == 'T') cg.loadGame(&t1);			// Tải game lập tức
					else if (cg.IS_RUNNING)
						if (!cg.pressable) 
							MOVING = ' ';
						else 
							MOVING = key;		
				}
				else {
					cg.exitGame(&t1);
					if (sound.joinable()) {
						sound.detach();
						sound = thread(SoundGameOverThread);
					}
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
	sound.join();
	return 0;
}

void SubThread() {
	short delay_running = cg.getDelay();

	thread sound(SoundThread);
	while (cg.IS_RUNNING) {

		// Cập nhật vị trí người chơi
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING, &sound);
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
				cg.pressable = false;	// Ngưng nhận phím
				cg.soundImpact();
				cg.getPeople()->resetPosition();
				cg.pressable = true;	// Tiếp tục nhận phím
			}
			delay_running = cg.getDelay();
		}

		//Kiểm tra đến đích 
		if (cg.getPeople()->isFinish()) {
			// Hiệu ứng chuyển level
			cg.pressable = false; 
			cg.upLevel();

			if (sound.joinable()) {
				sound.detach();
				sound = thread(SoundUpLevelThread);
			}
			if (cg.getLevel() < cg.getMaxLevel())
				cg.drawTime();

			// Chỉnh độ khó theo level
			cg.updateLevel();
			delay_running = cg.getDelay();
			cg.getPeople()->resetPosition();
			cg.pressable = true;

			// Tăng level
			cg.drawLevel();
		}
	}
	sound.join();
}

void SoundThread() {

}

void SoundMoveThread() {
	if (SOUND) {
		PlaySound(L"Sound/Choice.wav", NULL, SND_FILENAME);
	}
}

void SoundGameOverThread() {
	if (SOUND) {
		PlaySound(L"Sound/GameOver.wav", NULL, SND_FILENAME);
	}
}

void SoundUpLevelThread() {
	if (SOUND) {
		PlaySound(L"Sound/UpLevel.wav", NULL, SND_FILENAME);
	}
}