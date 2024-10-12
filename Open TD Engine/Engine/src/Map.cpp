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

void Map::render(sf::RenderWindow& window) {
	sprite.setPosition(0, 0);
	window.draw(sprite);
}

int Map::getWidth() {
	return mapWidth;
}

int Map::getHeight() {
	return mapHeight;
}