#include "draw.h"


void _setGreatTitle(unsigned char title_color) {
	Console::setColor(title_color);
	Console::gotoXY(10, 1); std::cout << "  ______ .______        ______        _______.     _______.";
	Console::gotoXY(10, 2); std::cout << " /      ||   _  \\      /  __  \\      /       |    /       |";
	Console::gotoXY(10, 3); std::cout << "|  ,----'|  |_)  |    |  |  |  |    |   (----`   |   (----`";
	Console::gotoXY(10, 4); std::cout << "|  |     |      /     |  |  |  |     \\   \\        \\   \\";
	Console::gotoXY(10, 5); std::cout << "|  `----.|  |\\  \\----.|  `--'  | .----)   |   .----)   |";
	Console::gotoXY(10, 6); std::cout << " \\______|| _| `._____| \\______/  |_______/    |_______/";

	Console::gotoXY(15, 10); std::cout << ".______        ______        ___       _______";
	Console::gotoXY(15, 11); std::cout << "|   _  \\      /  __  \\      /   \\     |       \\";
	Console::gotoXY(15, 12); std::cout << "|  |_)  |    |  |  |  |    /  ^  \\    |  .--.  |";
	Console::gotoXY(15, 13); std::cout << "|      /     |  |  |  |   /  /_\\  \\   |  |  |  |";
	Console::gotoXY(15, 14); std::cout << "|  |\\  \\----.|  `--'  |  /  _____  \\  |  '--'  |";
	Console::gotoXY(15, 15); std::cout << "| _| `._____| \\______/  /__/     \\__\\ |_______/";
}


void _setSmallTitle(unsigned char title_color) {
	Console::setColor(title_color);
	Console::gotoXY(32, 7); std::cout << "| |_| |__   ___";
	Console::gotoXY(10, 8); std::cout << " ____________________ | __| '_ \\ / _ \\ ____________________ ";
	Console::gotoXY(32, 9); std::cout << "| |_| | | |  __/";
	Console::gotoXY(33, 10); std::cout << "\\__|_| |_|\\___|";
}


void drawMenuTitle() {
	Sleep(300);

	_setGreatTitle(8);
	Sleep(300);

	_setGreatTitle(7);
	_setSmallTitle(3);
	Sleep(300);

	_setGreatTitle(15);
	_setSmallTitle(11);
	Sleep(300);

	Console::setColor(15);
}


void clearMenuTitle() {
	Sleep(300);

	_setGreatTitle(7);
	_setSmallTitle(3);
	Sleep(300);

	_setGreatTitle(8);
	_setSmallTitle(0);
	Sleep(300);

	_setGreatTitle(0);
	Sleep(300);

	Console::setColor(15);
}


void drawMenuFrame() {
	DoubleLineFrame main_menu_frame;

	// draw the column
	main_menu_frame = DoubleLineFrame::vertical;
	for (char i = 18; i <= 23; i++) {
		Console::gotoXY(32, i); putchar((unsigned char)main_menu_frame);
		Console::gotoXY(47, i); putchar((unsigned char)main_menu_frame);
	}

	// draw the line
	main_menu_frame = DoubleLineFrame::horizontal;
	Console::gotoXY(33, 18); std::cout << std::string(14, (unsigned char)main_menu_frame);
	Console::gotoXY(33, 23); std::cout << std::string(14, (unsigned char)main_menu_frame);

	// draw the corner
	main_menu_frame = DoubleLineFrame::left_up;
	Console::gotoXY(32, 18); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::right_up;
	Console::gotoXY(47, 18); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::left_down;
	Console::gotoXY(32, 23); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::left_down;
	Console::gotoXY(47, 23); putchar((unsigned char)main_menu_frame);
}

void drawMenuLines(unsigned char line_position) {
	Console::gotoXY(34, 19); std::cout << " Start Game ";
	Console::gotoXY(34, 20); std::cout << " Load Game  ";
	Console::gotoXY(34, 21); std::cout << "  Settings  ";
	Console::gotoXY(34, 22); std::cout << " Exit Game  ";

	Console::setColor(15 * 16);
	switch (line_position) {
	case 0:
		Console::gotoXY(34, 19); std::cout << " Start Game ";
		break;
	case 1:
		Console::gotoXY(34, 20); std::cout << " Load Game  ";
		break;
	case 2:
		Console::gotoXY(34, 21); std::cout << "  Settings  ";
		break;
	case 3:
		Console::gotoXY(34, 22); std::cout << " Exit Game  ";
		break;
	}

	Console::setColor(15);
}
