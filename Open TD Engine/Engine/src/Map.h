#ifndef MAP_H
#define MAP_H

#include "Input.h"
#include <iostream>

#define TILE_SIZE 16

class Map {
public:
	Map();
	Map(int width, int height, const std::string& tilesetPath);
	~Map() = default;

	void render(sf::RenderWindow& window);

	int getWidth();
	int getHeight();

private:
	int mapWidth;
	int mapHeight;

	sf::Texture texture;
	sf::Sprite sprite;

	std::vector<std::vector<int>> tileMap;
};

#endif // !MAP_H