#include "draw.h"


void _setGreatTitle(unsigned char title_color) {
	Console::setColor(title_color);
	Console::drawFromFileTransparent(
		"menu/GreatTitle.txt",
		COORD{ 40, 1 },
		(int)title_color
	);
}


void _setSmallTitle(unsigned char title_color) {
	Console::setColor(title_color);
	Console::drawFromFileTransparent(
		"menu/SmallTitle.txt",
		COORD{ 40, 7 },
		(int)title_color
	);
}


void drawTitle() {
	Sleep(300);

	_setGreatTitle((unsigned char)Color::dark_gray);
	Sleep(300);

	_setGreatTitle((unsigned char)Color::light_gray);
	_setSmallTitle((unsigned char)Color::dark_aqua);
	Sleep(300);

	_setGreatTitle((unsigned char)Color::white);
	_setSmallTitle((unsigned char)Color::aqua);
	Sleep(300);

	Console::setColor((int)Color::white);
}


void clearTitle() {
	Sleep(300);

	_setGreatTitle(7);
	_setSmallTitle(3);
	Sleep(300);

	_setGreatTitle(8);
	_setSmallTitle(0);
	Sleep(300);

	_setGreatTitle(0);
	Sleep(300);

	Console::setColor((int)Color::white);
}


void drawMainMenuFrame() {
	Console::drawFromFile(
		"menu/MainMenuFrame.txt",
		COORD{ 58, 18 },
		(int)(int)Color::white
	);
}

void drawMainMenuLines(unsigned char line_position) {
	Console::gotoXY(60, 19); std::cout << " Start Game ";
	Console::gotoXY(60, 20); std::cout << " Load Game  ";
	Console::gotoXY(60, 21); std::cout << "  Settings  ";
	Console::gotoXY(60, 22); std::cout << " Exit Game  ";

	Console::setColor(16 * (int)Color::white);
	switch (line_position) {
	case 0:
		Console::gotoXY(60, 19); std::cout << " Start Game ";
		break;
	case 1:
		Console::gotoXY(60, 20); std::cout << " Load Game  ";
		break;
	case 2:
		Console::gotoXY(60, 21); std::cout << "  Settings  ";
		break;
	case 3:
		Console::gotoXY(60, 22); std::cout << " Exit Game  ";
		break;
	}

	Console::setColor((int)Color::white);
}


void drawPauseMenuFrame() {
	Console::drawFromFile(
		"menu/PauseMenuFrame.txt",
		COORD{ 58, 20 },
		(int)(int)Color::white
	);
}


void drawPauseMenuLines(unsigned char line_position) {
	Console::gotoXY(60, 21); std::cout << "  Continue  ";
	Console::gotoXY(60, 22); std::cout << " Save game  ";
	Console::gotoXY(60, 23); std::cout << " Main menu  ";

	Console::setColor(16 * (int)Color::white);
	switch (line_position) {
	case 0:
		Console::gotoXY(60, 21); std::cout << "  Continue  ";
		break;
	case 1:
		Console::gotoXY(60, 22); std::cout << " Save Game  ";
		break;
	case 2:
		Console::gotoXY(60, 23); std::cout << " Main menu  ";
		break;
	}

	Console::setColor((int)Color::white);
}


void removePauseMenu(short X, short Y) {
	Console::setColor((int)Color::light_gray);
	
	// Để in ra dòng 133 (xem định nghĩa code page 437)
	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	Console::gotoXY(58, 20);
	std::cout << std::string(16, char(220)); // hình khối nằm
	for (char i = 21; i <= 24; i++) {
		Console::gotoXY(58, i);
		std::cout << std::string(16, ' ');
	}

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Nếu người chơi bị pause menu che đi, vẽ lại
	if ((X == 10 or X == 11 or X == 12 or X == 13) and Y == 4)
		Console::drawFromFile(
			"player/people.txt",
			COORD{ 2 + TILE_X * X + 5, 2 + TILE_Y * Y },
			(int)Color::blue
		);
	// Con vật và xe cộ không cần vì nó di chuyển liên tục, nên xuất hiện gần như lập tức
}


void drawSaveMenuFrame() {
	Console::drawFromFile(
		"menu/SaveMenuFrame.txt",
		COORD {50, 20},
		(int)Color::white
	);
}

void drawSaveMenuLines() {
	drawSaveMenuIcon('1', 52, 21);
	drawSaveMenuIcon('2', 59, 21);
	drawSaveMenuIcon('3', 66, 21);
	drawSaveMenuIcon('4', 73, 21);
}

void drawSaveMenuIcon(char filenumber, short trueX, short trueY) {
	std::ifstream f;
	f.open("SaveGame/" + std::string(1, filenumber) + ".txt");

	// vẽ khung mỗi nút. Nếu file tồn tại (có lưu trong đó) thì khung đó màu xanh, ngược lại màu đỏ
	if (f.is_open()) {
		Console::drawFromFile(
			"menu/SaveMenuIcon.txt",
			COORD{ trueX, trueY },
			(int)Color::green
		);
		Console::gotoXY(trueX + 2, trueY + 1);
		putchar(filenumber);
	}
	else {
		Console::drawFromFile(
			"menu/SaveMenuIcon.txt",
			COORD{ trueX, trueY },
			(int)Color::red
		);
	}

	f.close();
}

void removeSaveMenu(short X, short Y) {
	Console::setColor((int)Color::light_gray);

	SetConsoleCP(437);
	SetConsoleOutputCP(437);

	Console::gotoXY(50, 20);
	std::cout << std::string(30, char(220));
	for (char i = 21; i <= 24; i++) {
		Console::gotoXY(50, i);
		std::cout << std::string(30, ' ');
	}
	Console::gotoXY(50, 25);
	std::cout << std::string(30, char(220));

	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	if ((X >= 9 and X <= 13) and Y == 4)
		Console::drawFromFile(
			"player/people.txt",
			COORD{ 2 + TILE_X * X + 5, 2 + TILE_Y * Y },
			(int)Color::blue
		);
}
