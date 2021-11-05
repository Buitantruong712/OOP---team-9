#ifndef _GAME_
#define _GAME_


// this thing will control the playing, NOT the main menu


#include "draw.h"
// CPeople
#include "cpeople.h"
// CCollision
#include "bird.h"

#include <fstream>


class CGAME {

private:
	//CTRUCK * axt;
	//CCAR * axh;
	//CDINAUSOR * akl;
	std::vector<Bird> birds;	// xài thread
	CPEOPLE player;
public:
	CGAME();
	void drawGame();
	~CGAME();
	CPEOPLE getPeople();
	//CVEHICLE * getVehicle();
	std::vector <Bird> getAnimal();

	void resetGame();
	void exitGame(HANDLE); // thoát trò chơi, và quay lại menu
	void startGame(); // trò chơi bắt đầu
	void loadGame(/*std::istream*/);
	void saveGame(/*std::istream*/);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE); // 
	void updatePosPeople(char update);
	void updatePosVehicle();
	void updatePosAnimal();
};


#endif
