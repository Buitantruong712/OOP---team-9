#include "HandleConsole.h"
#include <time.h>
#include <fstream>
#include <string>
#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;

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
public:
	CGAME();
	~CGAME();
	void drawTitle();
	void drawMenu(short choice);
	void drawGame();
	void runMenu();
};

void drawCarMenu();
