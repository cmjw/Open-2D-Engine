#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

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

	void draw(sf::RenderWindow& window);

	void move(float dx, float dy, float deltaTime);

private:
	bool loadPlayerData();
	void initialize(); // loads and initializes data
};

#endif