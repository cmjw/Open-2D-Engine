#include "Input.h"

bool Input::upPressed() {
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	// this will be a constant eventually
}

bool Input::downPressed() {
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
}

bool Input::leftPressed() {
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
}

bool Input::rightPressed() {
	return (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
}