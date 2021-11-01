#include "Console.h"

void Console::drawGameBot() {
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "khungGame.txt", COORD{ 18, 2 }, (int)Color::gray);
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "start.txt", COORD{ 22, 34 }, (int)Color::red);
	Console::drawFromFile(GetStdHandle(STD_OUTPUT_HANDLE), "finish.txt", COORD{ 22, 4 }, (int)Color::red);
	//Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ 80, 33 }, (int)Color::lightblue);
}

void Console::drawFromFile(HANDLE hwnd, const string filename, COORD pos, int color) {
	string str;
	ifstream inp(filename);
	//setColor(color);
	SetConsoleTextAttribute(hwnd, color);
	while (!inp.eof()) {
		getline(inp, str);
		SetConsoleCursorPosition(hwnd, pos);
		cout << str;
		pos.Y++;
	}
	inp.close();
}


void Console::removeSpace(int x, int y) {
	for (int i = x - 1; i < x + 5; i++) {
		for (int j = y; j < y + 4; j++) {
			gotoXY(i, j);
			cout << " ";
		}
		cout << endl;
	}
}

void Console::setConsole() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	resizeConsole(2000, 2000);
	ShowCur(false);
	Sleep(1000);
	fixConsoleWindow();
}

// VÔ HIỆU HÓA NÚT PHÓNG TO MÀN HÌNH
void Console::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void Console::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Console::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::setColor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void Console::ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}