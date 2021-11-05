﻿#include "menu.h"


Menu::Menu() {
	Console::setConsole();

	line_position = 0;
	exit = false;

	drawMainMenu();
}


Menu::~Menu() {

}


void Menu::getInput() {
	char c;

	while (not exit) {
		c = toupper(_getch());
		setMenu(c);
	}
}


void Menu::setMenu(char input) {

	switch (input) {

	case 'W': case 'A':
		line_position--;
		if (line_position < 0)
			line_position = 3;
		break;

	case 'S': case 'D':
		line_position++;
		if (line_position > 3)
			line_position = 0;
		break;

	case 13: case 'Z': // Enter
		// Phụ thuộc vào bàn phím
		switch (line_position) {
		case 0:
			drawNewGame();
			// Nếu trò chơi kết thúc
			drawMainMenu();
			break;
		case 1:
			drawLoadGame();
			break;
		case 2:
			drawSettings();
			break;
		case 3:
			drawExitGame();
			break;
		}
		break;

	default:
		return;
	}

	drawMenuLines(line_position);
}


void Menu::drawMainMenu() {
	drawMenuTitle();
	drawMenuFrame();
	drawMenuLines(0);
}


void Menu::drawNewGame() {
	clearMenuTitle();
	_CGAME.startGame();
}


void Menu::drawLoadGame() {
	_CGAME.loadGame();
}


void Menu::drawSettings() {
	Console::gotoXY(0, 24);
	std::cout << "Coming soon";
	Sleep(1000);
	Console::gotoXY(0, 24);
	std::cout << std::string(15, ' ');
}


void Menu::drawExitGame() {
	exit = true;
}
