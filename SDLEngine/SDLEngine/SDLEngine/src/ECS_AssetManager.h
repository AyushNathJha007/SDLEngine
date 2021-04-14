#pragma once
#ifndef ECS_ASSET_MANAGER_H
#define ECS_ASSET_MANAGER_H

#include<string>
#include<map>
#include <SDL_ttf.h>
#include "ECS_FontManager.h"
#include "ECS_TextureManager.h"
#include "ECS_EntityManager.h"

class ECS_AssetManager
{
private:
	ECS_EntityManager* entityManager;
	std::map<std::string, SDL_Texture*> textureID_map;
	std::map<std::string, TTF_Font*> fontID_map;

public:
	ECS_AssetManager(ECS_EntityManager* entityManager);
	~ECS_AssetManager();
	void AddTexture(std::string TextureID, std::string filePath);
	void AddFont(std::string FontID, std::string filePath, int fontSize);
	SDL_Texture* GetTexture(std::string TextureID);
	TTF_Font* GetFont(std::string FontID);
	void ClearData();
	
};

#endif ECS_ASSET_MANAGER_H