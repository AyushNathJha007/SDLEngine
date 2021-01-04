#include "Game.h"
#include "ECS_EntityManager.h"
#include "Components/ECS_Tile_Component.h"
#include "Map.h"
#include <fstream>
#include<iostream>

extern ECS_EntityManager manager;
Map::Map(std::string textureID, int scale, int tileSize)
{
	this->textureID = textureID;
	this->scale = scale;
	this->tileSize = tileSize;
}

void Map::Map_Load(std::string filePath, int sizeX, int sizeY)
{
	std::fstream mapFile;
	mapFile.open(filePath);
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			char ch;
			mapFile.get(ch);
			int sourceRectY = atoi(&ch)*tileSize;
			mapFile.get(ch);
			int sourceRectX = atoi(&ch)*tileSize;
			//std::cout << sourceRectX << " " << sourceRectY<<endl;
			Map_AddTile(sourceRectX, sourceRectY, x*(scale*tileSize), y*(scale*tileSize));
			mapFile.ignore();
		}
	}
	mapFile.close();
}

void Map::Map_AddTile(int sourceRectX, int sourceRectY, int x, int y)
{
	ECS_Entity& newTile(manager.AddEntity("Tile", TILEMAP_LAYER));
	newTile.AddComponent<ECS_Tile_Component>(sourceRectX, sourceRectY, x, y,tileSize, scale, textureID);

}


