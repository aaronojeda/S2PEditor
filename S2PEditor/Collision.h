#ifndef SDL_Game_Programming_Book_Header_h
#define SDL_Game_Programming_Book_Header_h

#include "SDL.h"
#include "Vector2D.h"

static bool RectRect(SDL_Rect A, SDL_Rect B)
{
	// if the bottom of A is less than the top of B - no collision
	if (A.y + A.h <= B.y)  { return false; }

	// if the top of A is more than the bottom of B = no collision
	if (A.y >= B.y + B.h)  { return false; }

	// if the right of A is less than the left of B - no collision
	if (A.x + A.w <= B.x) { return false; }

	// if the left of A is more than the right of B - no collision
	if (A.x >= B.x + B.w)  { return false; }

	// otherwise there has been a collision
	return true;
}

#endif
