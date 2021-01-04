
#include "ECS_Tile_Component.h"
#include "../ECS_AssetManager.h"

ECS_Tile_Component::ECS_Tile_Component(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureID)
{
	texture = Game::assetManager->GetTexture(assetTextureID);
	sourceRect.x = sourceRectX;
	sourceRect.y = sourceRectY;
	sourceRect.w = sourceRect.h = tileSize;

	destinationRect.x = x;
	destinationRect.y = y;
	destinationRect.w = destinationRect.h = tileScale * tileSize;

	position.x = x;
	position.y = y;
}

ECS_Tile_Component::~ECS_Tile_Component()
{
	SDL_DestroyTexture(texture);
}

void ECS_Tile_Component::Update(float deltaTime)
{
	destinationRect.x = position.x - Game::camera.x;
	destinationRect.y = position.y - Game::camera.y;
}

void ECS_Tile_Component::Render()
{
	ECS_TextureManager::Draw(texture, sourceRect, destinationRect, SDL_FLIP_NONE);
}
