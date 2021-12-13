#include "CGame.h"

char MOVING;
CGAME cg;
bool theme = true, sound = false, music = false, endless_mode = false;
short set_max_hearts = 5;

int main() {
	srand(time(NULL));

	bool old_theme = cg.getTheme();
	cg.drawTitle();

	while (1) {

		if (old_theme != cg.getTheme()) {	// Nếu theme được chỉnh thì vẽ lại
			cg.drawTitle();
			old_theme = cg.getTheme();
		}

		int menuChoice = cg.runMenu();

		// - - - - - - START GAME / LOAD GAME - - - - - -
		if (menuChoice == 0 || menuChoice == 1) {
			if (menuChoice == 0)
				cg.startGame();
			else {
				cg.loadGame(); // Nếu có load, is_running = true, nếu false, vòng lặp dưới sẽ không được chạy
				if (cg.is_running == false) {	// Nếu không chọn load game thì không cho chạy đến thread
					COORD pos = { (short)(Console::getMidHorizontal() - 15), Console::getMidVertical() };
					Console::removeSpace(pos.X, pos.Y, pos.X + 31, pos.Y + 5);
					continue;
				}
			}

			int temp;
			thread t1(SubThread);

			// Vòng lặp mới như song song với SubThread
			while (cg.is_running) {
				temp = toupper(_getch());
				if (!cg.getPeople()->isDead()) {
					// Nếu nhấn Esc
					if (temp == (int)Key::ESCAPE || temp == 'P') {	// Tạm dừng trò chơi
						cg.pauseGame(t1);
						if (!cg.is_running) {	// Nếu người chơi muốn thoát ra
							cg.drawTitle();
							break;
						}
					}
					else if (temp == 'L') {		// Lưu game lập tức
						cg.is_running = false;
						cg.saveGame(t1);
						cg.is_running = true;
					}
					else if (temp == 'T') {		// Tải game lập tức
						cg.is_running = false;
						cg.loadGame();
						Console::drawFromFile(
							"Menu/OverLappingPart.txt",
							COORD{ (short)(Console::getMidHorizontal() - 15), Console::getMidVertical() },
							(int)Color::LIGHT_GRAY
						);
						cg.is_running = true;
						cg.resumeGame(t1);
					}

					if (cg.is_running) {	// Bắt đầu tiếp
						MOVING = temp;
					}
				}
				else {
					cg.gameOver();
					cg.exitGame(t1);    // Nhấn nút bất kỳ để quay lại menu
					cg.drawTitle();
					break;
				}
			}
		}
		// - - - - - - SETTINGS - - - - - -
		else if (menuChoice == 2) {
			cg.settings();
			cg.drawMainMenu(menuChoice);
		}
		// - - - - - - EXIT GAME - - - - - -
		else return 0;
	}
}