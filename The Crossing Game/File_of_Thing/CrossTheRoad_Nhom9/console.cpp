#include "Console.h"


/// 
/// - - - - - - - - - - - - CONSOLE - - - - - - - - - - - - 
/// 

// Vô hiệu hoá nút phóng to màn hình
void Console::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Thay đổi kích thước màn hình
void Console::resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

/// 
/// - - - - - - - - - - - - CON TRỎ - - - - - - - - - - - - 
/// 

// Di chuyển con trỏ đến một vị trí
void Console::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Đổi màu ký tự
void Console::setColor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Làm ẩn con trỏ
void Console::showCursor(bool CursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

/// 
/// - - - - - - - - - - - - VẼ - - - - - - - - - - - - 
/// 

// Vẽ từ file
void Console::drawFromFile(const std::string filename, COORD pos, int color) {
	std::string str;
	std::ifstream f(filename);

	setColor(color);
	if (f.is_open()) {
		while (not f.eof()) {
			getline(f, str);
			gotoXY(pos.X, pos.Y);
			std::cout << str;
			pos.Y++;
		}
	}
	else {
		std::cerr << "Cannot find the " << filename << "\n";
	}
	f.close();

	setColor((int)Color::white);
}

// Vẽ từ file nhưng dấu cách không được in ra (tránh bị chồng lên)
void Console::drawFromFileTransparent(const std::string filename, COORD pos, int color) {
	std::string str;
	std::ifstream f(filename);
	setColor(color);
	if (f.is_open()) {
		short _posX;
		while (not f.eof()) {
			_posX = pos.X;
			getline(f, str);
			gotoXY(_posX, pos.Y);
			for (auto& i : str) {
				_posX++;
				if (i == ' ')
					gotoXY(_posX, pos.Y);
				else
					putchar(i);
			}
			pos.Y++;
		}
	}
	else {
		std::cerr << "Cannot find the " << filename << "\n";
	}
	f.close();

	setColor((int)Color::white);
}


// Xoá sprite
void Console::removeSpace(int x, int y) { // Lúc này, chiều cao chỉ là 4 ký tự (cho khớp với từng hàng)
	for (int i = y; i < y + TILE_Y - 2; i++) {
		gotoXY(x, i);
		std::cout << std::string(5, ' ');
	}
}

/// 
/// - - - - - - - - - - - - KHÁC - - - - - - - - - - - - 
/// 

// Thiết lập mặc định
void Console::setConsole() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	resizeConsole(2000, 2000);
	showCursor(false);
	Sleep(1000);
	fixConsoleWindow();
}

// Thiết lập trò chơi
void Console::drawGameBot() {
	Console::drawFromFile("map/frame.txt", COORD{ 3, 0 }, (int)Color::light_gray);
}

// Xoá toàn bộ console
void Console::clearScreen() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}
