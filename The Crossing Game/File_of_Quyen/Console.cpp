#include "Console.h"


int midVertical() {
	return m_height / 2;
}

int midHorizontal() {
	return m_width / 2;
}


void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLongPtr(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLongPtr(consoleWindow, GWL_STYLE, style);
}

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



int getSize() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return columns * getSizeHelper + rows;
}

string getClipboardText() {
	string text;

	if (OpenClipboard(NULL))
	{
		HANDLE clip;
		clip = GetClipboardData(CF_TEXT);
		// lock and copy
		text = (LPSTR)GlobalLock(clip);
		// unlock 
		GlobalUnlock(clip);
		CloseClipboard();
	}

	return text;
}

void clrscr()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void showCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 10;
	info.bVisible = TRUE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

void printString(string s, int row, int begin, int end, size_t cursorPos, size_t cursorPosConsole) {
	hideCursor();
	--end;
	size_t len;

	gotoXY(begin, row);
	for (len = begin; len <= end; ++len)
		cout << " ";

	gotoXY(begin, row);
	len = s.length();
	if (len <= end - begin + 1)
		cout << s;
	else {
		for (size_t i = cursorPos - (cursorPosConsole - begin); i <= cursorPos - cursorPosConsole + end; ++i)
			cout << s[i];
	}
	showCursor();
}

void goLeft(size_t& cursor1, size_t& cursor2, int begin) {
	--cursor1;
	if (cursor1 < cursor2 - begin)
		--cursor2;
}

void goRight(size_t& cursor1, size_t& cursor2, int end, string s, int step) {
	cursor1 += step;
	cursor2 += step;
	if (cursor2 > end)
		cursor2 = end - (s.length() - cursor1);
}



