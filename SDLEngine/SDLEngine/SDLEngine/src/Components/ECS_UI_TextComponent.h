#pragma once
#ifndef ECS_UI_TEXTCOMPONENT_H
#define ECS_UI_TEXTCOMPONENT_H

#include "../ECS_Component.h"
#include "../Game.h"
#include <SDL.h>
#include <SDL_ttf.h>

class ECS_UI_TextComponent:public ECS_Component{
private:
	SDL_Rect position;
	std::string text;
	std::string fontFamily;
	SDL_Color color;
	SDL_Texture* texture;
public:
	ECS_UI_TextComponent(int x, int y, std::string text, std::string fontFamily,const SDL_Color& color);
	

	void SetText(std::string text, std::string fontFamily);

	void Render() override;
	
};

#endif