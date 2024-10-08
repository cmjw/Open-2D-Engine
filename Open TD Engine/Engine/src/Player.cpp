#include "Player.h"

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {

}

void Player::initialize() {
	sprite.setSize(sf::Vector2f(50.f, 50.f));  // 50x50 pixel square
	sprite.setFillColor(sf::Color::Blue);     // Set the color of the shape
	sprite.setPosition(800 / 2, 600 / 2);  // Start in the center of the
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
