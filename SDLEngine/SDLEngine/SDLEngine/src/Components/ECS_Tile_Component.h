#pragma once
#ifndef ECS_TILE_COMPONENT_H
#define ECS_TILE_COMPONENT_H

#include <SDL.h>
#include "../../libs/glm/glm.hpp"
#include "../ECS_EntityManager.h"

class ECS_Tile_Component:public ECS_Component
{
public:
	SDL_Texture* texture;
	SDL_Rect sourceRect;
	SDL_Rect destinationRect;
	glm::vec2 position;
	ECS_Tile_Component(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureID);
	~ECS_Tile_Component();
	void Update(float deltaTime) override;
	void Render() override;

};

#endif
