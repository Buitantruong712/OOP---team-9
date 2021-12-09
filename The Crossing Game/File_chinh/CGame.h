#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CCar.h"
#include "CTruck.h"

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
	const string PAUSE_MENU[3] = { "CONTINUE ", "SAVE GAME ", "MAIN MENU" };

	CTRUCK* axt;		int axt_size;
	CCAR* axh;		    int axh_size;
	CBIRD* ac;			int ac_size;
	CBIRD* birds;		int birds_size;		// (thay thế sau)
	CCAR* cars;			int cars_size;		// (thay thế sau)
	CPEOPLE* cn;

public:
	bool IS_RUNNING;
	CGAME();
	~CGAME();

	// Vẽ
	void drawTitle();					// Title game	
	void drawMainMenu(short choice);	// Menu chính
	void drawPauseMenu(short choice);	// Menu dừng game
	void drawGame();					// Trong game
	void clearPauseMenu();
	// Chạy menu
	short runMenu();		
	short runPauseMenu();

	// Getter
	CPEOPLE* getPeople() { return cn; };
	CVEHICLE* getTruck() { return axt; };
	CVEHICLE* getCar() { return axh; };
	CANIMAL* getBird() { return ac; };
	CVEHICLE* getCar2() { return cars; };			// (thay thế sau)
	CANIMAL* getBird2() { return birds; };			// (thay thế sau)
	int getTruckSize() { return axt_size; };
	int getCarSize() { return axh_size; };
	int getBirdSize() { return ac_size; };
	int getCarSize2() { return cars_size; };		// (thay thế sau)
	int getBirdSize2() { return birds_size; };		// (thay thế sau)

	// Thao tác game
	void resetGame();					// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread &t);			// Thực hiện thoát Thread 
	void startGame();					// Thực hiện bắt đầu vào trò chơi
	//void loadGame(istream);			// Thực hiện tải lại trò chơi đã lưu
	//void saveGame(istream);			// Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(thread &t);			// Tạm dừng Thread
	void resumeGame(thread &t);					// Quay lai Thread
	void gameOver();

	void updatePosPeople(char);		//Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();			//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehical();		//Thực hiện cho CDINAUSOR & CBIRD di chuyển
};
#endif

extern char MOVING;
extern CGAME cg;
inline void SubThread() {
	while (cg.IS_RUNNING) {

		// Kiểm tra sống chết
		if (!cg.getPeople()->isDead()) {
			cg.updatePosPeople(MOVING);
		}
		MOVING = ' ';
		cg.updatePosVehical();
		cg.updatePosAnimal();

		// Kiểm tra va chạm
		if (cg.getPeople()->isImpact(cg.getCar(), cg.getCarSize())
			|| cg.getPeople()->isImpact(cg.getTruck(), cg.getTruckSize())
			|| cg.getPeople()->isImpact(cg.getBird(), cg.getBirdSize())
			|| cg.getPeople()->isImpact(cg.getCar2(), cg.getCarSize2())
			|| cg.getPeople()->isImpact(cg.getBird2(), cg.getBirdSize2())
			)
		{
			cg.getPeople()->subHeart();
			cg.getPeople()->drawHealthBar();
			cg.getPeople()->resetPosition();
		}

		// Kiểm tra đến đích 
		if (cg.getPeople()->isFinish()) {
			//level++;
			cg.getPeople()->resetPosition();
		}

		Sleep(100);
	}
}