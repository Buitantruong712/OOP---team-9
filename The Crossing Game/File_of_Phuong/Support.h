#pragma once

#include <iostream>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
#include <thread>
#include <mmsystem.h>

using namespace std;

void gotoXY(int, int);
void fixConsoleWindow();
void resizeConsole(int, int);
void removeScollbar();
void hidePtr();
void textColor(int color);
void fontSize(int);