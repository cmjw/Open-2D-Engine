#include "Map.h"

Map::Map() {

}

Map::Map(int width, int height, const std::string& tilesetPath) {
	mapWidth = width;
	mapHeight = height;

	if (!tilesetTexture.loadFromFile("./../Data/tileset.png")) {
		std::cerr << "Tileset error" << std::endl;
		return;
	}

	tileSprite.setTexture(tilesetTexture);
}

void Map::render(sf::RenderWindow& window) {
	tileSprite.setPosition(0, 0);

	window.draw(tileSprite);
}

int Map::getWidth() {
	return mapWidth;
}

int Map::getHeight() {
	return mapHeight;
}