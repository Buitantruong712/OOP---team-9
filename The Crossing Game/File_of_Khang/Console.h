#pragma once
#ifndef _MY_FUNCTION_H
#define _MY_FUNCTION_H
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <MMSystem.h>
#include <fstream>
#include<string>
#include<vector>
using namespace std;


#pragma execution_character_set("UTF-8");

enum Status { UP, DOWN, OTHER };

struct WASD {
	Status wasd;
};

enum class Color
{
	black,
	blue,
	green,
	aqua,
	red,
	purple,
	yellow,
	white,
	gray,
	lightblue,
	lightgreen,
	lightaqua,
	lightred,
	lightpurple,
	lightyellow,
	brightwhite
};

class Graphics
{
public:
	static void SetColor(HANDLE, int);
	static void GotoXY(HANDLE, COORD);
	static void DrawTexts(HANDLE, std::string, COORD, int);
	static void DrawGraphicsFixed(HANDLE, const std::string, COORD, int);
	static void DrawGraphics(HANDLE, const std::string, int);
	static void RemoveSpace(int, int);
};

// VÔ HIỆU HÓA NÚT PHÓNG TO MÀN HÌNH
void fixConsoleWindow();

void ShowCur(bool CursorVisibility);
int inputKey();

// THAY ĐỔI KÍCH THƯỚC MÀN HÌNH CONSOLE
void resizeConsole(int width, int height);


// TRỎ TỚI VỊ TRÍ X, Y
void gotoXY(int x, int y);

// TÔ MÀU
void textcolor(int x);
void SetColor(WORD color);
void setConsole();
void drawGameBot();
#endif