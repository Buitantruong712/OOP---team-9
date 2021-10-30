#include "Support.h"

// Move cursor on console
void gotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Disable maximize/minimize
void fixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

// Modify size of console window
void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Disable scrollbar
void removeScrollbar() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = {info.srWindow.Right - info.srWindow.Left + 1,
                      info.srWindow.Bottom - info.srWindow.Top + 1};
    SetConsoleScreenBufferSize(handle, new_size);
}

// Hide pointer when process the program
void hidePtr() {
    HANDLE handle;
    CONSOLE_CURSOR_INFO ConCurInf;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &ConCurInf);
}

// Modify text's color
void textColor(int color) {
    HANDLE handle;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, color);
}

// Modify text's size
void fontSize(int Size) {
    pair<int, int> s[9] = {{4, 6}, {6, 8}, {8, 8}, {16, 8}, {5, 12}, {7, 12}, {16, 12}, {12, 16}, {10, 18}};
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X = s[Size].first;
    lpConsoleCurrentFontEx->dwFontSize.Y = s[Size].second;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lpConsoleCurrentFontEx);
}