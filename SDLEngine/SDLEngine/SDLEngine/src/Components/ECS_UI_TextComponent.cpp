
#include "ECS_UI_TextComponent.h"

ECS_UI_TextComponent::ECS_UI_TextComponent(int x, int y, std::string text, std::string fontFamily,const SDL_Color& color)
{
	this->position.x = x;
	this->position.y = y;
	this->text = text;
	this->fontFamily = fontFamily;
	this->color = color;
	//this->texture = texture;
	SetText(text, fontFamily);
}


void ECS_UI_TextComponent::SetText(std::string text, std::string fontFamily)
{
	SDL_Surface* surface = TTF_RenderText_Blended(Game::assetManager->GetFont(fontFamily), text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
}

void ECS_UI_TextComponent::Render()
{
	ECS_FontManager::Draw(texture, position);
}
