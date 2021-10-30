#include <Windows.h>

#define WIDTH  1500
#define HEIGHT 800
#define HELPGETSIZE 100

enum class Color {
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTAQUA,
	LIGHTRED,
	LIGHTPURPLE,
	LIGHTYELLOW,
	LIGHTWHITE
};

// DEFAULT FUNCTION
void fixConsoleWindow();
void resizeConsole(int width, int height);

void textcolor(int color);
void GotoXY(int x, int y);
void ShowCur(bool CursorVisibility);

int getSize();

int getMidVertical();
int getMidHoritonal();

// MY CODE
void initConsole();

