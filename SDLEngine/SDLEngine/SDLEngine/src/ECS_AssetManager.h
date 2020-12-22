#pragma once
#ifndef ECS_ASSET_MANAGER_H
#define ECS_ASSET_MANAGER_H

#include<string>
#include<map>
#include "ECS_TextureManager.h"
#include "ECS_EntityManager.h"

class ECS_AssetManager
{
private:
	ECS_EntityManager* entityManager;
	std::map<std::string, SDL_Texture*> textureID_map;

public:
	ECS_AssetManager(ECS_EntityManager* entityManager);
	~ECS_AssetManager();
	void AddTexture(std::string TextureID, std::string filePath);
	SDL_Texture* GetTexture(std::string TextureID);
	
	void ClearData();
	
};

#endif ECS_ASSET_MANAGER_H