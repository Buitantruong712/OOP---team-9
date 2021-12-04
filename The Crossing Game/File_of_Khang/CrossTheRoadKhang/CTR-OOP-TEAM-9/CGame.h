#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CCar.h"
#include "CTruck.h"
#include"CHelicopter.h"
#include"Snail.h"
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
	const short SETTING_MENU[4] = {0, 1, 2, 3};// hỗ trợ option setting
	bool theme = 1, sound = 1, music = 1; // hỗ trợ option setting
	const string PAUSE_MENU[3] = { "CONTINUE ", "SAVE GAME ", "MAIN MENU" };
	CPEOPLE cn;
	CHELICOPTER* tts;		int tts_size;
	CBIRD* birds;		int birds_size;
	CSNAIL* snails;	int snails_size;
	CCAR* cars;			int cars_size;
	CTRUCK* trucks;		int trucks_size;
	bool exit_game;

public:
	CGAME();
	~CGAME();

	// Vẽ
	void drawTitle();					// Title game	
	void drawMainMenu(short choice);	// Menu chính
	void drawSettingMenu(short choice,bool &the,bool &mus,bool &sou); // Setting menu
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
	void setting();
	void pauseGame(/*HANDLE*/);		// Tạm dừng Thread
	void resumeGame();			// Quay lai Thread

	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();		//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehical();	//Thực hiện cho CDINAUSOR & CBIRD di chuyển
};
#endif 

