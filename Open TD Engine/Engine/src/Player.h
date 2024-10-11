#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

using json = nlohmann::json;

class Player {
public:
	int width;
	int height;

	float movementSpeed;

	sf::RectangleShape sprite;

	Player();
	~Player();

	// ability to reload sprite / change character?

	void render(sf::RenderWindow& window);
	void move(float dx, float dy, float deltaTime);

private:
	bool loadPlayerData(std::string str);
	void initialize(); // loads and initializes data
	void cleanup();

	const std::string startingGraphic = "../Data/Player.json";
};

#endif