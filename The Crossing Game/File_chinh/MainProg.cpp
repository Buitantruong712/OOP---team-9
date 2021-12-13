#include "CGame.h"

char MOVING;
CGAME cg;
bool theme = true, sound = false, music = false, endless_mode = false;
short set_max_hearts = 5;

int main() {
	srand(time(NULL));

	bool old_theme = theme;

	cg.drawTitle();

	while (1) {

		if (old_theme != theme) {	// Nếu theme được chỉnh thì vẽ lại
			cg.drawTitle();
			old_theme = theme;
		}

		int menuChoice = cg.runMainMenu();

// - - - - - - - - - - - - - - - - - - START GAME / LOAD GAME - - - - - - - - - - - - - - - - - -
		if (menuChoice == 0 || menuChoice == 1) {

			if (menuChoice == 0)
				cg.startGame();
			else {
				cg.loadGame(); // Nếu có load, is_running = true, nếu false, vòng lặp dưới sẽ không được chạy
				if (cg.is_running == false) {	// Nếu không chọn load game thì không cho chạy đến thread
					continue;
				}
			}

			int temp;
			thread t1(SubThread);

			// Vòng lặp mới như song song với SubThread
			while (cg.is_running) {
				temp = toupper(_getch());
				if (!cg.getPeople()->isDead()) {
					
					if (temp == (int)Key::ESCAPE || temp == 'P') {	// Tạm dừng trò chơi
						cg.pauseGame(&t1);
						if (!cg.is_running) break;	// Nếu người chơi muốn thoát ra
					}
					else if (temp == 'L') cg.saveGame(&t1);			// Lưu game lập tức
					else if (temp == 'T') cg.loadGame(&t1);			// Tải game lập tức
						
					if (cg.is_running) MOVING = temp;		// Bắt đầu tiếp

					if (cg.winning()) break;
				}
				else {
					cg.gameOver();
					break;
				}
			}
			cg.exitGame(&t1);
			cg.drawTitle();
		}
// - - - - - - - - - - - - - - - - - - SETTINGS - - - - - - - - - - - - - - - - - -
		else if (menuChoice == 2) {
			cg.runSettings();
			cg.drawMainMenu(menuChoice);
		}
// - - - - - - - - - - - - - - - - - - EXIT GAME - - - - - - - - - - - - - - - - - -
		else return 0;
	}
}

void SubThread() {
	short delay_running = 12;
	short delay = 12;

	thread tSound(SoundThread);

	while (cg.is_running) {

		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING, &tSound);
		}
		MOVING = ' ';
		Sleep(10);
		delay_running--;

		if (delay_running == 0) {
			cg.updatePosVehicle();
			cg.runTraffic();
			cg.updatePosAnimal();

			// Kiểm tra va chạm
			if (
				cg.getPeople()->isImpact(cg.getCar(), cg.getCarSize())
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
			delay_running = delay;
		}
		//Kiểm tra đến đích 
		if (cg.getPeople()->isFinish()) {

			// Tăng level
			cg.level++;

			// Hiệu ứng chuyển level
			cg.pressable = false;
			Console::drawFromFile("Map/EmptyFrame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP + 5 }, (int)Color::LIGHT_GRAY);
			cg.drawLevel(cg.level);
			if (sound) {
				PlaySound(L"Sound/UpLevel.wav", NULL, SND_FILENAME);
			}
			if (endless_mode || cg.level < cg.max_level)
				cg.drawTime(cg.level);

			// Chỉnh level

			switch (cg.level) {

			case 2:
				delay = 7;
				cg.resetGame(1, 4, 1, 3, 2);
				break;

			case 3:
				cg.resetGame(1, 4, 2, 3, 2);
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
				if (!endless_mode) {
					cg.gameWinner();
				}
				else {
					delay = 1;	// Xài thông số ở vòng 12
				}
				break;
			}

			delay_running = delay;
			// Đặt lại vị trí người chơi
			cg.getPeople()->resetPosition();
			// Và vẽ lại các con vật (xem thêm hàm drawObject())
			cg.drawObjects();
			// Và cho người chơi nhập
			cg.pressable = true;
		}
	}
	cg.pressable = false; // Khi chết, không nhấn được nữa

	tSound.join();
}

void MusicThread() {
	if (music)
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
