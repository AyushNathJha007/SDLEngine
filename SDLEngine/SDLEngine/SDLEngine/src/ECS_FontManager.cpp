
#include "ECS_FontManager.h"

TTF_Font * ECS_FontManager::LoadFont(const std::string filePath, int fontSize)
{
	return TTF_OpenFont(filePath.c_str(), fontSize);
	
}

void ECS_FontManager::Draw(SDL_Texture * texture, SDL_Rect position)
{
	SDL_RenderCopy(Game::renderer,texture, NULL, &position);
}
