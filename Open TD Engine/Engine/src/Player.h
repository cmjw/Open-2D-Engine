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
	int height; // temporary

	// Add player as an sf::RectangleShape
	sf::RectangleShape playerShape;

	Player();
	~Player();

	void initialize(); // loads and initializes data'

	void draw(sf::RenderWindow *window);

private:
	void loadPlayerData();
};

#endif