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
#include<thread>
#include<vector>
using namespace std;

#pragma execution_character_set("UTF-8");

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

class Console
{
public:
	static void drawFromFile(HANDLE, const string, COORD, int);
	static void removeSpace(int, int);
	static void fixConsoleWindow();
	static void ShowCur(bool CursorVisibility);
	static int inputKey();
	static void resizeConsole(int width, int height);
	static void gotoXY(int x, int y);
	static void setColor(int x);
	static void setConsole();
	static void drawGameBot();
};
#endif