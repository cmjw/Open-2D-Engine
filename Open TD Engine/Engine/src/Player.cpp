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
	sprite.setPosition(0, 0);  // Start in the center of the
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::move(float dx, float dy, float deltaTime) {
	float movementSpeed = 200.f;

	sprite.move(dx * movementSpeed * deltaTime, dy * movementSpeed * deltaTime);
}