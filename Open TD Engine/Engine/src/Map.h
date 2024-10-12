#ifndef MAP_H
#define MAP_H

#include "Input.h"

#define TILE_SIZE 16

class Map {
public:
	Map();
	Map(int width, int height, const std::string& tilesetPath);
	~Map() = default;

	int getWidth();
	int getHeight();

private:
	int mapWidth;
	int mapHeight;

};

#endif // !MAP_H
