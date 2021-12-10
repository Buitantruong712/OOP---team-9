#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CMonkey.h"
#include "CCar.h"
#include "CTruck.h"
#include "CHelicopter.h"

enum class Key {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13
};

class CGAME {
private:
	const string MAIN_MENU[4] = { "START GAME", "LOAD GAME ", "SETTINGS  ", "EXIT      " };
	const short SETTING_MENU[4] = { 0, 1, 2, 3 };			// hỗ trợ option setting
	bool theme = 1, sound = 1, music = 1;					// hỗ trợ option setting
	const string PAUSE_MENU[3] = { "CONTINUE ", "SAVE GAME ", "MAIN MENU" };
	CBIRD* ac;			int ac_size;
	CMONKEY* ak;        int ak_size;
	CTRUCK* axt;		int axt_size;
	CCAR* axh;		    int axh_size;
	CHELICOPTER* att;   int att_size;	
	CPEOPLE* cn;

public:
	bool IS_RUNNING;
	CGAME();
	~CGAME();
	int level = 1;

	// Vẽ
	void drawTitle();					// Title game	
	void drawMainMenu(short choice);	// Menu chính
	void drawPauseMenu(short choice);	// Menu dừng game
	void drawSettingMenu(short choice, bool& the, bool& mus, bool& sou); // Setting menu

	void drawLevel(int);
	void drawGame();					// Trong game
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
	int getBirdSize() { return ac_size; };
	int getMonkeySize() { return ak_size; };
	int getCarSize() { return axh_size; };
	int getTruckSize() { return axt_size; };
	int getHelicopterSize() { return att_size; };

	// Thao tác game
	void resetGame();					// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread& t);			// Thực hiện thoát Thread 
	void startGame();					// Thực hiện bắt đầu vào trò chơi
	void setting();                     // Thực hiện khi chọn setting
	//void loadGame(istream);			// Thực hiện tải lại trò chơi đã lưu
	//void saveGame(istream);			// Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(thread& t);			// Tạm dừng Thread
	void resumeGame(thread& t);			// Quay lai Thread
	void gameOver();

	void updatePosPeople(char);			//Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();				//Thực hiện cho CTRUCK & CCAR & CHELICOPTER di chuyển
	void updatePosVehical();			//Thực hiện cho CMONKEY & CBIRD di chuyển
};
#endif

extern char MOVING;
extern CGAME cg;
inline void SubThread() {
	int a =8;
	int b = 8;
	while (cg.IS_RUNNING) {

		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING);
		}
		MOVING = ' ';
		Sleep(10);
		a --;
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
			b --;
			cg.level++;
			cg.drawLevel(cg.level);
			cg.getPeople()->resetPosition();
		}
	}
}