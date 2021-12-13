#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CMonkey.h"
#include "CCar.h"
#include "CTruck.h"
#include "CHelicopter.h"
#include "CTraffic.h"


class CGAME {
private:
	const string MAIN_MENU[4] = { "START GAME ", " LOAD GAME ", " SETTINGS ", "   EXIT   " };
	const string PAUSE_MENU[3] = { "CONTINUE ", "SAVE GAME ", "MAIN MENU" };
	CBIRD* ac;			short ac_size = 0;
	CMONKEY* ak;        short ak_size = 0;
	CCAR* axh;		    short axh_size = 0;
	CTRUCK* axt;		short axt_size = 0;
	CHELICOPTER* att;   short att_size = 0;	// (thay thế sau)
	CTRAFFIC* light1;	// hàng 1 cho trực thăng
	CTRAFFIC* light2;	// hàng 4 cho xe tải
	CTRAFFIC* light3;	// hàng 5 cho xe ô tô
	CPEOPLE* cn;

public:
	bool is_running;
	bool press = 1;
	CGAME();
	~CGAME();
	int level = 1;

	// Vẽ
	void drawTitle();					// Title game	
	void drawMainMenu(short choice);	// Menu chính
	void drawSettingsMenu(short choice);// Menu cài đặt
	void drawSaveMenu();				// Menu save
	void drawLoadMenu();				// Menu load
	void drawPauseMenu(short choice);	// Menu dừng game

	void drawLevel(short);
	void drawTime(short);
	void drawGame();					// Trong game
	void drawObjects();
	void clearPauseMenu();
	// Chạy menu
	short runMenu();
	short runPauseMenu();

	// Getter
	CPEOPLE* getPeople() { return cn; };
	CANIMAL* getBird() { return ac; };
	CANIMAL* getMonkey() { return ak; };
	CVEHICLE* getTruck() { return axt; };
	CVEHICLE* getCar() { return axh; };
	CVEHICLE* getHelicopter() { return att; };
	short getBirdSize() { return ac_size; };
	short getMonkeySize() { return ak_size; };
	short getCarSize() { return axh_size; };
	short getTruckSize() { return axt_size; };
	short getHelicopterSize() { return att_size; };
	bool getTheme() { return theme; };

	// Thao tác game
	void resetGame(short tt_size, short c_size, short xt_size, short k_size, short xh_size);
										// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread& t);			// Thực hiện thoát Thread 
	void startGame();					// Thực hiện bắt đầu vào trò chơi
	void settings();                    // Thực hiện khi chọn setting
	void loadGame();					// Thực hiện tải lại trò chơi đã lưu
	void saveGame(thread& t);			// Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(thread& t);			// Tạm dừng Thread
	void resumeGame(thread& t);			// Quay lai Thread
	void gameWinner();
	void gameOver();

	void updatePosPeople(char, bool);		//Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();			//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehicle();		//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void runTraffic();
};


extern char MOVING;
extern CGAME cg;

inline void SubThread() {
	short delay_running = 12;
	short delay = 12;

	while (cg.is_running) {

		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING, cg.press);
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
			cg.press = 0;
			Console::drawFromFile("Map/EmptyFrame.txt", COORD{ (short)Border::LEFT - 2, (short)Border::TOP + 5 }, (int)Color::LIGHT_GRAY);
			cg.drawLevel(cg.level);
			if (endless_mode || cg.level < (short)Key::ENTER)
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
		}
	}
}

#endif