#pragma once
#ifndef ECS_FONTMANAGER_H
#define ECS_FONTMANAGER_H

#include <SDL_ttf.h>
#include "./Game.h"
#include <string>

class ECS_FontManager {
public:
	static TTF_Font* LoadFont(const std::string filePath,int fontSize);
	static void Draw(SDL_Texture* texture, SDL_Rect  position);
};

#endif
