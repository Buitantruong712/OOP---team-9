//#include "Graphics.h"
//
//void Graphics::SetColor(HANDLE hwnd, int color)
//{
//	SetConsoleTextAttribute(hwnd, color);
//}
//
//void Graphics::DrawGraphicsFixed(HANDLE hwnd, const std::string filename, COORD pos, int color)
//{
//	std::string str;
//	std::ifstream inp(filename);
//	SetColor(hwnd, color);
//	while (!inp.eof())
//	{
//		std::getline(inp, str);
//		GotoXY(hwnd, pos);
//		std::cout << str;
//		pos.Y++;
//	}
//	inp.close();
//}
//
//
//void Graphics::RemoveSpace(int x, int y) {
//	for (int i = x - 1; i < x + 5; i++) {
//		for (int j = y; j < y + 4; j++) {
//			gotoXY(i, j);
//			cout << " ";
//		}
//		cout << endl;
//	}
//}
////void Graphics::DrawGraphics(HANDLE hwnd, const std::string filename, int color)
////{
////	std::string str;
////	std::ifstream inp(filename);
////	SetColor(hwnd, color);
////	while (!inp.eof())
////	{
////		std::getline(inp, str);
////		std::cout << str;
////		pos.Y++;
////	}
////	inp.close();
////}
//
//void Graphics::GotoXY(HANDLE hwnd, COORD pos)
//{
//	SetConsoleCursorPosition(hwnd, pos);
//}
//
//void Graphics::DrawTexts(HANDLE hwnd, std::string str, COORD pos, int color)
//{
//	GotoXY(hwnd, pos);
//	SetConsoleTextAttribute(hwnd, color);
//	std::cout << str;
//}