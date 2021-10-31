#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include<string>
#include<vector>
#include <conio.h>
#include <stdio.h>
using namespace std;

static const int getSizeHelper = 1000;
static const int rightShift = 20;
const int m_height = 200;
const int m_width = 200;
const int MAX = 80;
#define NUM_OF_THREAD 2 // dinh nghia so thread can tao

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



	void resizeConsole(int, int);
	int getSize();
	string getClipboardText();
	void printString(string, int, int, int, size_t, size_t);

	void textcolor(int x);
	void fixConsoleWindow();
	void gotoXY(int x, int y);
	void clrscr();
	void hideCursor();
	void showCursor();

	//HANDLE CreateThread(
	//	LPSECURITY_ATTRIBUTES lpThreadAttributes,
	//	SIZE_T dwStackSize,
	//	LPTHREAD_START_ROUTINE lpStartAddress,
	//	LPVOID lpParameter,
	//	DWORD dwCreationFlags,
	//	LPDWORD lpThreadId
	//);
//	//Tra ve threaed :
//	DWORD GetThreadId(
//		HANDLE Thread
//	);
//	//tra ve do uu tien dinh thoi
//	int GetThreadPriority(
//		HANDLE hThread
//	);
//
////tam ngung thread
//	DWORD SuspendThread(
//		HANDLE hThread
//	);
//
////phuc hoi thread
//	DWORD ResumeThread(
//		HANDLE hThread
//	);
//
//	//Huy thread :
//	BOOL TerminateThread(
//		HANDLE hThread,
//		DWORD dwExitCode
//	);

#endif