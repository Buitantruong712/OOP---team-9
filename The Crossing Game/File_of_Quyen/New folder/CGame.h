#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CCar.h"
#include "CTruck.h"
#include "CTraffic.h"

enum class Key {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13
};

class CGAME {
private:
	const string MAIN_MENU[4] = { "START GAME", "LOAD GAME", "SETTINGS ", "  EXIT   " };
	const string PAUSE_MENU[3] = { "CONTINUE ", "SAVE GAME ", "MAIN MENU" };
	CPEOPLE cn;
	CCAR* cars_2;		int cars_2_size;
	CBIRD* birds;		int birds_size;
	CBIRD* birds_2;		int birds_2_size;
	CCAR* cars;			int cars_size;
	CTRUCK* trucks;		int trucks_size;
	CTraffic* light1;
	CTraffic* light2;
	CTraffic* light3;
	bool exit_game;

public:
	CGAME();
	~CGAME();

	// Vẽ
	void drawTitle();					// Title game	
	void drawMainMenu(short choice);	// Menu chính
	void drawPauseMenu(short choice);	// Menu dừng game
	void drawGame();					// Trong game

	// Chạy menu
	void runMenu();

	// Getter
	CPEOPLE getPeople();

	// Thao tác game
	void resetGame();			// Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
	void exitGame(HANDLE);		// Thực hiện thoát Thread 
	void startGame();			// Thực hiện bắt đầu vào trò chơi
	void loadGame(istream);		// Thực hiện tải lại trò chơi đã lưu
	void saveGame(istream);		// Thực hiện lưu lại dữ liệu trò chơi
	void pauseGame(/*HANDLE*/);		// Tạm dừng Thread
	void resumeGame();			// Quay lai Thread

	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();		//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehical();	//Thực hiện cho CDINAUSOR & CBIRD di chuyển
	void runTraffic();
};
#endif 