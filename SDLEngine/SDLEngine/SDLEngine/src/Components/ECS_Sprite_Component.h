#pragma once
#ifndef ECS_SPRITE_COMPONENT_H
#define ECS_SPRITE_COMPONENT_H

//#include "../ECS_Component.h"
#include "../ECS_TextureManager.h"
#include "../ECS_AssetManager.h"
#include "ECS_Transform_Component.h"
#include "./ECS_Animation.h"
#include <SDL.h>

class ECS_Sprite_Component :public ECS_Component
{
public:
	//---For UI Components-----//
	bool isFixedOnScreen;
	//----End UI Comp------//
	ECS_Transform_Component* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRect, destRect;
	//For animations
	bool isAnimated;
	int numberOfFrames;
	int animSpeed;
	std::map<std::string, ECS_Animation> animations;
	std::string currentAnimationName;
	unsigned int animationIndex = 0;
public:
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	ECS_Sprite_Component(std::string filePath);
	ECS_Sprite_Component(std::string filePath, int animSpeed, int numberOfFrames, bool hasDirections, bool isFixed);
	void PlayAnimation(std::string currentAnimationName);
	void SetTexture(std::string TextureID);
	void Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;
};

#endif