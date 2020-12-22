#include <string>
#include "ECS_AssetManager.h"

ECS_AssetManager::ECS_AssetManager(ECS_EntityManager* entityManager)
{

}

void ECS_AssetManager::AddTexture(std::string TextureID, std::string filePath)
{
	textureID_map.emplace(TextureID, ECS_TextureManager::LoadTexture(filePath));
}

SDL_Texture* ECS_AssetManager::GetTexture(std::string TextureID)
{
	return textureID_map[TextureID];
}

void ECS_AssetManager::ClearData()
{
	textureID_map.clear();
}
