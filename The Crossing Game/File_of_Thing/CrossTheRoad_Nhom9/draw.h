#ifndef _DRAW_
#define _DRAW_


// Nơi để vẽ code


#include "console.h"


// Code bị lỗi. Xem dòng 88 và 89 ở console.cpp

//enum class SingleLineFrame {
//	left_up = 218,
//	right_up = 191,
//	right_down = 217,
//	left_down = 192,
//
//	horizontal = 196,
//	vertical = 179,
//	vertical_broken_bar = 221,
//
//	t_shape = 194,
//	t_shape_inverted = 193,
//	thorn_symbol = 195,
//	thorn_symbol_inverted = 180,
//
//	cross = 197
//};
//
//
//enum class DoubleLineFrame {
//	left_up = 201,
//	right_up = 187,
//	right_down = 188,
//	left_down = 200,
//
//	horizontal = 205,
//	vertical = 186,
//
//	t_shape = 203,
//	t_shape_inverted = 202,
//	thorn_symbol = 204,
//	thorn_symbol_inverted = 185,
//
//	cross = 206
//};


void drawTitle();
void clearTitle();

void drawMainMenuFrame();
void drawMainMenuLines(unsigned char);

void drawPauseMenuFrame();
void drawPauseMenuLines(unsigned char);
void removePauseMenu(short, short);	// Vì nó đã chồng lên hình vẽ nên cần vẽ lại khúc đó

void drawSaveMenuFrame();
void drawSaveMenuLines();
void drawSaveMenuIcon(char, short, short);
void removeSaveMenu(short, short); // Tương tự như removePauseMenu()


#endif
