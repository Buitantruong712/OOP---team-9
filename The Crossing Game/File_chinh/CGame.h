#ifndef _CGAME_H
#define _CGAME_H

#include "CPeople.h"
#include "CBird.h"
#include "CCar.h"

enum class Key {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13
};

class CGAME {
private:
	const string MENU[4] = { "START GAME", "LOAD GAME", "SETTINGS", "EXIT" };
	CPEOPLE cn;
	CBIRD* ac;
	int acNumber;
	CCAR* axh;
	int axhNumber;
public:
	CGAME();
	~CGAME();

	// Vẽ
	void drawTitle();				// Title game	
	void drawMenu(short choice);	// Menu chính
	void drawGame();				// Trong game

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
	void pauseGame(HANDLE);		// Tạm dừng Thread
	void resumeGame();			// Quay lai Thread

	void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
	void updatePosAnimal();		//Thực hiện cho CTRUCK & CCAR di chuyển
	void updatePosVehical();	//Thực hiện cho CDINAUSOR & CBIRD di chuyển
};
#endif 


