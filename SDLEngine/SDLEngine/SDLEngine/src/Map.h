#pragma once
#ifndef MAP_H
#define MAP_H

#include <string>

class Map {
private:
	std::string textureID;
	int scale;
	int tileSize;
public:
	Map(std::string textureID, int scale, int tileSize);
	~Map();
	void Map_Load(std::string filePath, int sizeX, int sizeY);
	void Map_AddTile(int sourceX, int sourceY, int x, int y);
};

#endif