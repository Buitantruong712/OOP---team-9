#include "draw.h"


void _setGreatTitle(unsigned char title_color) {
	TextColor(title_color);
	gotoXY(10, 1); std::cout << "  ______ .______        ______        _______.     _______.";
	gotoXY(10, 2); std::cout << " /      ||   _  \\      /  __  \\      /       |    /       |";
	gotoXY(10, 3); std::cout << "|  ,----'|  |_)  |    |  |  |  |    |   (----`   |   (----`";
	gotoXY(10, 4); std::cout << "|  |     |      /     |  |  |  |     \\   \\        \\   \\";
	gotoXY(10, 5); std::cout << "|  `----.|  |\\  \----.|  `--'  | .----)   |   .----)   |";
	gotoXY(10, 6); std::cout << " \\______|| _| `._____| \\______/  |_______/    |_______/";

	gotoXY(15, 10); std::cout << ".______        ______        ___       _______";
	gotoXY(15, 11); std::cout << "|   _  \\      /  __  \\      /   \\     |       \\";
	gotoXY(15, 12); std::cout << "|  |_)  |    |  |  |  |    /  ^  \\    |  .--.  |";
	gotoXY(15, 13); std::cout << "|      /     |  |  |  |   /  /_\\  \\   |  |  |  |";
	gotoXY(15, 14); std::cout << "|  |\\  \\----.|  `--'  |  /  _____  \\  |  '--'  |";
	gotoXY(15, 15); std::cout << "| _| `._____| \\______/  /__/     \\__\\ |_______/";
}


void _setSmallTitle(unsigned char title_color) {
	TextColor(title_color);
	gotoXY(32, 7); std::cout << "| |_| |__   ___";
	gotoXY(10, 8); std::cout << " ____________________ | __| '_ \\ / _ \\ ____________________ ";
	gotoXY(32, 9); std::cout << "| |_| | | |  __/";
	gotoXY(33, 10); std::cout << "\\__|_| |_|\\___|";
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

	TextColor(15);
}

void drawMenuFrame() {
	DoubleLineFrame main_menu_frame;

	// draw the column
	main_menu_frame = DoubleLineFrame::vertical;
	for (char i = 18; i <= 23; i++) {
		gotoXY(32, i); putchar((unsigned char)main_menu_frame);
		gotoXY(47, i); putchar((unsigned char)main_menu_frame);
	}

	// draw the line
	main_menu_frame = DoubleLineFrame::horizontal;
	gotoXY(33, 18); std::cout << std::string(14, (unsigned char)main_menu_frame);
	gotoXY(33, 23); std::cout << std::string(14, (unsigned char)main_menu_frame);

	// draw the corner
	main_menu_frame = DoubleLineFrame::left_up;
	gotoXY(32, 18); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::right_up;
	gotoXY(47, 18); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::left_down;
	gotoXY(32, 23); putchar((unsigned char)main_menu_frame);
	main_menu_frame = DoubleLineFrame::left_down;
	gotoXY(47, 23); putchar((unsigned char)main_menu_frame);
}

void drawMenuLines(unsigned char line_position) {
	gotoXY(34, 19); std::cout << " Start Game ";
	gotoXY(34, 20); std::cout << " Load Game  ";
	gotoXY(34, 21); std::cout << "  Settings  ";
	gotoXY(34, 22); std::cout << " Exit Game  ";

	TextColor(15 * 16);
	switch (line_position) {
	case 0:
		gotoXY(34, 19); std::cout << " Start Game ";
		break;
	case 1:
		gotoXY(34, 20); std::cout << " Load Game  ";
		break;
	case 2:
		gotoXY(34, 21); std::cout << "  Settings  ";
		break;
	case 3:
		gotoXY(34, 22); std::cout << " Exit Game  ";
		break;
	}

	TextColor(15);
}
