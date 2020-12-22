#pragma once
#ifndef ECS_SPRITE_COMPONENT_H
#define ECS_SPRITE_COMPONENT_H

//#include "../ECS_Component.h"
#include "../ECS_TextureManager.h"
#include "../ECS_AssetManager.h"
#include "ECS_Transform_Component.h"
#include <SDL.h>

class ECS_Sprite_Component :public ECS_Component
{
private:
	ECS_Transform_Component* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRect, destRect;
public:
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	ECS_Sprite_Component(std::string filePath);
	void SetTexture(std::string TextureID);
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
};

#endif