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
	bool pressable = true;
	CGAME();
	~CGAME();
	const int max_level = 13;
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
	short runMainMenu();
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

	bool winning() { return (!endless_mode && level == max_level); };

	// Thao tác game
	void resetGame(short tt_size, short c_size, short xt_size, short k_size, short xh_size);
										// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(thread* t);			// Thực hiện thoát Thread 
	void startGame();					// Thực hiện bắt đầu vào trò chơi
	void runSettings();					// Thực hiện khi chọn setting
	void loadGame();					// Thực hiện tải lại trò chơi đã lưu
	void loadGame(thread* t);			
	void saveGame(thread* t);			// Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(thread* t);			// Tạm dừng Thread
	void resumeGame(thread* t);			// Quay lai Thread
	void gameWinner();
	void gameOver();

	void updatePosPeople(char, thread* t);		//Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();			//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehicle();		//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void runTraffic();
};

inline void SubThread();
inline void SoundThread();
inline void MusicThread();

#endif