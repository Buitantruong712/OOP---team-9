#ifndef _DRAW_
#define _DRAW_


// A place for drawing anything, including menu, mob, and anything else


#include "console.h"


enum class SingleLineFrame {
	left_up = 218,
	right_up = 191,
	right_down = 217,
	left_down = 192,

	horizontal = 196,
	vertical = 179,
	vertical_broken_bar = 221,

	t_shape = 194,
	t_shape_inverted = 193,
	thorn_symbol = 195,
	thorn_symbol_inverted = 180,

	cross = 197
};


enum class DoubleLineFrame {
	left_up = 201,
	right_up = 187,
	right_down = 188,
	left_down = 200,

	horizontal = 205,
	vertical = 186,

	t_shape = 203,
	t_shape_inverted = 202,
	thorn_symbol = 204,
	thorn_symbol_inverted = 185,

	cross = 206
};


void drawMenuTitle();
void clearMenuTitle();

void drawMenuFrame();
void drawMenuLines(unsigned char line_position);


#endif
