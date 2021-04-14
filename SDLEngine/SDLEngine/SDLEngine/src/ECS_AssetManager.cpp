#include <string>
#include "ECS_AssetManager.h"

ECS_AssetManager::ECS_AssetManager(ECS_EntityManager* entityManager)
{

}

void ECS_AssetManager::AddTexture(std::string TextureID, std::string filePath)
{
	textureID_map.emplace(TextureID, ECS_TextureManager::LoadTexture(filePath));
}

void ECS_AssetManager::AddFont(std::string FontID, std::string filePath, int fontSize)
{
	fontID_map.emplace(FontID,ECS_FontManager::LoadFont(filePath,fontSize));
}

SDL_Texture* ECS_AssetManager::GetTexture(std::string TextureID)
{
	return textureID_map[TextureID];
}

TTF_Font * ECS_AssetManager::GetFont(std::string FontID)
{
	return fontID_map[FontID];
}

void ECS_AssetManager::ClearData()
{
	textureID_map.clear();
	fontID_map.clear();
}
