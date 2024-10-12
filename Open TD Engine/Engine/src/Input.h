#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Input {
public:
	Input();
	Input(sf::Keyboard keyboard);
	~Input();

	bool upPressed();
	bool downPressed();
	bool leftPressed();
	bool rightPressed();
	bool menuPressed();

private:
	sf::Keyboard keyboard;
};

#endif