#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

class Input {
public:
	static bool upPressed();
	static bool downPressed();
	static bool leftPressed();
	static bool rightPressed();
	static bool menuPressed();
};

#endif