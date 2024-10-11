#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

class Sprite {
public:
	Sprite();
	Sprite(sf::Texture& texture, int width, int height, int index);
	~Sprite();

	void setPosition(float x, float y);
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite sprite;
	int width;
	int height;
};

#endif // !SPRITE_H