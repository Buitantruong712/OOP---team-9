#ifndef _MENU_
#define _MENU_


// Vẽ Menu, khác với CGAME


#include "CGame.h"


class Menu {

private:
	char line_position; // vị trí con trỏ ở các mục
	bool exit; // nếu true, thoát màn hình

	CGAME _CGAME;

public:
	Menu();
	~Menu();

	// Nhận giá trị nhập
	void getInput();
	void setMenu(char);

	// Vẽ
	void drawMainMenu();
	void drawNewGame();
	void drawLoadGame();
	void drawSettings();
	void drawExitGame();
};


#endif
