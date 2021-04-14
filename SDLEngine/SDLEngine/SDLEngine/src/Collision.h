#pragma once
#ifndef COLLISION_H
#define COLLISION_H

#include <SDL.h>

class Collision {
public:
	//Axis Aligned Bouding Box type coliision detection
	//BB type: Rectangle
	static bool CheckCollisonAABB(const SDL_Rect& RectA, const SDL_Rect& RectB);
};

#endif
