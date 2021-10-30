#ifndef _GAME_
#define _GAME_


// this thing will control the playing, NOT the main menu


#include "draw.h"

#include <fstream>


class CGAME {

private:
	//CTRUCK * axt;
	//CCAR * axh;
	//CDINAUSOR * akl;
	//CBIRD * ac;
	//CPEOPLE cn;
public:
	CGAME();
	void drawGame();
	~CGAME();
	//CPEOPLE getPeople();
	//CVEHICLE * getVehicle();
	//CANIMAL * getAnimal();
	void resetGame();
	void exitGame(HANDLE); // this will exit the game, but NOT the console app
	void startGame(); // the game will start
	void loadGame(/*std::istream*/);
	void saveGame(/*std::istream*/);
	void pauseGame(HANDLE);
	void resumeGame(HANDLE); // main function for looping
	void updatePosPeople(char update);
	void updatePosVehicle();
	void updatePosAnimal();
};


#endif
