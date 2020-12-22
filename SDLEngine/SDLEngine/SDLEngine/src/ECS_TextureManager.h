#pragma once
#ifndef ECS_TEXTURE_MANAGER_H
#define ECS_TEXTURE_MANAGER_H

#include "Game.h"
#include<string>

class ECS_TextureManager
{
public:
	static SDL_Texture* LoadTexture(std::string filePath);
	static void Draw(SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destinationRect, SDL_RendererFlip flip);
};

#endif
