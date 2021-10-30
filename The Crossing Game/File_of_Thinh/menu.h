#ifndef _MENU_
#define _MENU_


// Draw a main menu screen when starting the game


#include "cgame.h"


class Menu {

private:
	unsigned char line_position; // number with 1 byte
	bool exit; // if true, the console will close

	CGAME _CGAME;

public:
	Menu();
	~Menu();

	// Set the situation based on input
	void getInput();
	void setMenu(char input);

	// Draw the menu and the rest
	void drawMainMenu();
	void drawNewGame();
	void drawLoadGame();
	void drawSettings();
	void drawExitGame();
};


#endif
