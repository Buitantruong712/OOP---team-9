#ifndef _CONSOLE_H
#define _CONSOLE_H

#include <windows.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <thread>
#include <stdlib.h>
#include <time.h>

using namespace std;

#pragma execution_character_set("UTF-8")	// Sử dụng UTF-8
#pragma comment (lib, "winmm.lib")			// Cho phép xài nhạc

// Độ dài và rộng của khung
#define WIDTH_CONSOLE  1500
#define HEIGHT_CONSOLE 800
#define HELP_GET_SIZE 100

// Mỗi ô người di chuyển ngang 5 cao 5 (riêng xe ngang 15)
#define TILE_X 5
#define TILE_Y 5
#define TILE_X_CAR 15

// Số lượng ô trong khung game
#define MAX_MASK_X 24
#define MAX_MASK_Y 6

//#define COLUMNS Console::getSize() / HELP_GET_SIZE
//#define ROWS Console::getSize() % HELP_GET_SIZE

// Thao tác bên cài đặt/settings
extern bool theme, sound, music, endless_mode;
extern short set_max_hearts;

// Tọa độ viền của khung game
enum class Border {
	LEFT = 7,
	RIGHT = TILE_X * MAX_MASK_X + LEFT,
	TOP = 6,
	BOTTOM = TILE_Y * MAX_MASK_Y + TOP,
};

// Bảng 16 màu cơ bản của Microsoft
enum class Color {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_CYAN,
	DARK_RED,
	DARK_MAGENTA,
	DARK_YELLOW,
	LIGHT_GRAY,
	GRAY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE
};

// Thao tác phím
enum class Key {
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	ENTER = 13,
	ESCAPE = 27
};

// Thao tác khác trên console app
class Console {
public:
	// Thay đổi màn hình console (thay đổi và cố định kích thước)
	static void resizeConsole(int width, int height);
	static void fixConsoleWindow();

	// Thao tác con trỏ 
	static void gotoXY(int x, int y);
	static void showCursor(bool CursorVisibility);

	// Thay đổi màu
	static void setColor(int x);

	// Xóa màn hình console
	static void clearScreen();

	// Vẽ
	static void drawFromFile(const string, COORD, int);
	static void removeSpace(short, short, bool isCar = 0);
	static void removeSpace(short, short, short, short);

	// Lấy kích thước của console
	static short getSize();
	static short getMidVertical();
	static short getMidHorizontal();

	// Khác
	static void setConsole();
};
#endif