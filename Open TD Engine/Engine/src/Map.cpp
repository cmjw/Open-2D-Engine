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

void Map::loadMapDataFromFile(const std::string& mapDataPath) {
	std::ifstream file(mapDataPath);
	if (!file.is_open()) {
		std::cerr << "Error: could not open map data file " << mapDataPath << std::endl;
		return;
	}

	nlohmann::json jsonData;
	
	try {
		file >> jsonData;
	}
	catch (const nlohmann::json::parse_error& e) {
		std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
		file.close();
		return;
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		file.close();
		return;
	}
	file.close();


}

void Map::render(sf::RenderWindow& window) {
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			int posX = mapData[j][i];
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