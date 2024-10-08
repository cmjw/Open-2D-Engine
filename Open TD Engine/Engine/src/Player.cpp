#include "Player.h"

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {

}

void Player::initialize() {
	player.setSize(sf::Vector2f(50.f, 50.f));  // 50x50 pixel square
	player.setFillColor(sf::Color::Blue);     // Set the color of the shape
	player.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);  // Start in the center of the
}

void Player::draw(sf::RenderWindow& window) {

}
