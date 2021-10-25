#include "Console.h"

void drawGameBot() {
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "khungGame.txt", COORD{ 18, 2 }, (int)Color::gray);
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "start.txt", COORD{ 22, 34 }, (int)Color::red);
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "finish.txt", COORD{ 22, 4 }, (int)Color::red);
	Graphics::DrawGraphicsFixed(GetStdHandle(STD_OUTPUT_HANDLE), "people.txt", COORD{ 80, 33 }, (int)Color::lightblue);
}

void Graphics::SetColor(HANDLE hwnd, int color)
{
	SetConsoleTextAttribute(hwnd, color);
}

void Graphics::DrawGraphicsFixed(HANDLE hwnd, const std::string filename, COORD pos, int color)
{
	std::string str;
	std::ifstream inp(filename);
	SetColor(hwnd, color);
	while (!inp.eof())
	{
		std::getline(inp, str);
		GotoXY(hwnd, pos);
		std::cout << str;
		pos.Y++;
	}
	inp.close();
}


void Graphics::RemoveSpace(int x, int y) {
	for (int i = x - 1; i < x + 5; i++) {
		for (int j = y; j < y + 4; j++) {
			gotoXY(i, j);
			cout << " ";
		}
		cout << endl;
	}
}

void Graphics::GotoXY(HANDLE hwnd, COORD pos)
{
	SetConsoleCursorPosition(hwnd, pos);
}

void Graphics::DrawTexts(HANDLE hwnd, std::string str, COORD pos, int color)
{
	GotoXY(hwnd, pos);
	SetConsoleTextAttribute(hwnd, color);
	std::cout << str;
}

void setConsole() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	resizeConsole(2000, 2000);
	ShowCur(false);
	Sleep(1000);
	fixConsoleWindow();
}
// VÔ HIỆU HÓA NÚT PHÓNG TO MÀN HÌNH
void fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// THAY ĐỔI KÍCH THƯỚC MÀN HÌNH CONSOLE
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// TRỎ TỚI VỊ TRÍ X, Y
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// TÔ MÀU
void textcolor(int x) {
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}



