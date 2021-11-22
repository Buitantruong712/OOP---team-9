#ifndef _MY_FUNCTION_H
#define _MY_FUNCTION_H


#include <iostream>
//#include <iomanip>
#include <fstream>

#include <conio.h>
#include <windows.h>
//#include <MMSystem.h>

#include <string>
#include <thread>
#include <vector>

#include <stdlib.h>


#pragma execution_character_set("UTF-8")


#define LEFT_BORDER 2
#define RIGHT_BORDER 128	// do ảnh xét theo góc trên trái, không phải trung tâm,
							// nên 133 sẽ bị trừ đi 5 ký tự vì chiều dài của ảnh là 5


// Mỗi ô dài 5 ký tự và cao 4 ký tự
#define TILE_X 5
#define TILE_Y 5
// Tổng cộng có 25 ô ở hàng ngang và 7 ô hàng dọc
#define MAX_MASK_X 24
#define MAX_MASK_Y 7

enum class Color {
	black, dark_blue, dark_green, dark_aqua,
	dark_red, dark_magneta, dark_yellow, light_gray,
	dark_gray, blue, green, aqua,
	red, magneta, yellow, white
};



class Console {
public:
	// Thay đổi màn hình console (thay đổi và cố định kích thước)
	static void resizeConsole(int width, int height);
	static void fixConsoleWindow();
	static void fixConsoleFont();

	// Thao tác con trỏ (di chuyển con trỏ, làm con trỏ không hiện và đổi màu ký tự)
	static void gotoXY(int x, int y);
	static void setColor(int x);
	static void showCursor(bool CursorVisibility);

	// Vẽ
	static void drawFromFile(const std::string, COORD, int);
	static void drawFromFileTransparent(const std::string, COORD, int);
	static void removeSpace(int, int);

	// Khác
	static void setConsole();
	static void drawGameBot();
	static void clearScreen();
};
#endif