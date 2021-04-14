#pragma once
#ifndef ECS_COLLIDER_COMPONENT_H
#define ECS_COLLIDER_COMPONENT_H

#include <SDL.h>
#include"../Game.h"
#include "../ECS_EntityManager.h"
#include "./ECS_Transform_Component.h"

class ECS_Collider_Component :public ECS_Component
{
public:
	std::string colliderTag;
	SDL_Rect collider;
	SDL_Rect sourceRect;
	SDL_Rect destRect;
	ECS_Transform_Component* transform;

	ECS_Collider_Component(std::string colliderTag, int x, int y, int width, int height);
	void Initialize() override;
	void Update(float deltaTime) override;
	/*void Render() override {
		SDL_Rect Projectile{
		(int)collider.x,
		(int)collider.y,
		32,
		32
	};
		SDL_RenderFillRect(Game::renderer, &Projectile);
	}*/


};

#endif