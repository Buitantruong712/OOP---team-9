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


// Mỗi ô dài 5 ký tự và cao 4 ký tự
#define TILE_X 5
#define TILE_Y 5
// Tổng cộng có 25 ô ở hàng ngang và 7 ô hàng dọc
#define MAX_MASK_X 24
#define MAX_MASK_Y 7

enum class Color {
	black, blue, green, aqua,
	red, purple, yellow, white,
	gray, lightblue, lightgreen, lightaqua,
	lightred, lightpurple, lightyellow, brightwhite
};



class Console {
public:
	// Thay đổi màn hình console (thay đổi và cố định kích thước)
	static void resizeConsole(int width, int height);
	static void fixConsoleWindow();

	// Thao tác con trỏ (di chuyển con trỏ, làm con trỏ không hiện và đổi màu ký tự)
	static void gotoXY(int x, int y);
	static void setColor(int x);
	static void showCursor(bool CursorVisibility);

	// Chưa xài
	static int inputKey();

	// Vẽ
	static void drawFromFile(const std::string, COORD, int);
	static void removeSpace(int, int);

	static void setConsole();
	static void drawGameBot();
	static void clearScreen();
};
#endif