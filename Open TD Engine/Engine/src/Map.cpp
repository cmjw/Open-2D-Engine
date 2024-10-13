#include "Map.h"

Map::Map() {

}

Map::Map(int width, int height, const std::string& tilesetPath) {
	mapWidth = width;
	mapHeight = height;

	if (!texture.loadFromFile("./../Data/tileset.png")) {
		exit(-1);
	}
	sprite.setTexture(texture);
}

void Map::loadMapData(const std::vector<std::vector<int>>& mapData) {
	this->mapData = mapData;
}

void Map::render(sf::RenderWindow& window) {
	std::vector<std::vector<int>> data = {
		{0,1,0,1},
		{1,1,1,1},
		{0,0,0,0}
	};

	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			int posX = data[j][i];
			int posY = 0;

			sprite.setTextureRect(sf::IntRect(TILE_SIZE * posX, TILE_SIZE * posY, TILE_SIZE, TILE_SIZE));

			sprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
			window.draw(sprite);
		}
	}
}

int Map::getWidth() {
	return mapWidth;
}

int Map::getHeight() {
	return mapHeight;
}