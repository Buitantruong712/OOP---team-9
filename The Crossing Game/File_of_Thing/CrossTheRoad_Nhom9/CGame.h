#ifndef _GAME_
#define _GAME_


// kiểm soát phần chơi game, KHÔNG PHẢI phần main menu


#include "draw.h"
// CPeople
#include "CPeople.h"
#include "CAnimal.h"
#include "CVehicle.h"

#include <fstream>


enum PauseState {
	RESUME,
	EXIT
};


class CGAME {

private:
	//CTRUCK * axt;
	//CDINAUSOR * akl;
	std::vector<Bird> birds;	// xài thread
	std::vector<Car> cars;
	CPEOPLE player;

	short level;
	short state;

public:
	CGAME();
	void drawGame();
	~CGAME();
	CPEOPLE getPeople();
	std::vector <Car> getVehicle();
	std::vector <Bird> getAnimal();

	void resetGame();
	void exitGame();			// thoát trò chơi, và quay lại menu
	void startGame();			// trò chơi bắt đầu
	void loadGame();
	void saveGame();
	void setSaveFile(char);
	void pauseGame();			// ngưng vòng lặp
	void resumeGame();			// chạy vòng lặp
	void movePeople(char&);		// thay đổi vị trí người chơi
	void moveVehicle();			// thay đổi vị trí xe cộ
	void moveAnimal();			// thay đổi vị trí con vật
};


#endif
