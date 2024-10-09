#include "Player.h"

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {

}

void Player::initialize() {
	sprite.setSize(sf::Vector2f(50.f, 50.f)); 
	sprite.setFillColor(sf::Color::Blue);    
	sprite.setPosition(0, 0); 

	movementSpeed = 200.f;
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::move(float dx, float dy, float deltaTime) {
	float newDx = dx * movementSpeed * deltaTime;
	float newDy = dy * movementSpeed * deltaTime;

	// collisions?

	sprite.move(newDx, newDy);
}