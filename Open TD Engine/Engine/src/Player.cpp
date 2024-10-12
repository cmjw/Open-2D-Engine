#include "Player.h"

using json = nlohmann::json;

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {
	cleanup();
}

void Player::initialize() {
	if (!loadPlayerData(startingGraphic)) {
		// throw error
	}

	sprite.setSize(sf::Vector2f(width, height)); 
	sprite.setFillColor(sf::Color::Blue);    
	sprite.setPosition(0, 0); 

	movementSpeed = 200.f;
}

bool Player::loadPlayerData(std::string playerGraphic) {
	// eventually this is saved as some "starting graphic"

	std::ifstream file(playerGraphic);

	if (!file.is_open()) {
		std::cerr << "Could not open file: " << playerGraphic << std::endl;
		return false;
	}

	json playerData;

	// try to read from Player.json
	try {
		file >> playerData;  
	} catch (const json::parse_error& e) {
		std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
		file.close();
		return false;
	} catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		file.close();
		return false;
	}

	file.close();

	width = playerData["size"]["width"];
	height = playerData["size"]["height"];

	return true;
}

void Player::render(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::updateMovement(float deltaTime) {
	if (Input::upPressed()) {
		move(0, -1, deltaTime);  // Move up
	}
	if (Input::downPressed()) {
		move(0, 1, deltaTime);   // Move down
	}
	if (Input::leftPressed()) {
		move(-1, 0, deltaTime);  // Move left
	}
	if (Input::rightPressed()) {
		move(1, 0, deltaTime);   // Move right
	}
}

void Player::move(float dx, float dy, float deltaTime) {
	float newX = dx * movementSpeed * deltaTime;
	float newY = dy * movementSpeed * deltaTime;

	// collisions?

	sprite.move(newX, newY);
}

void Player::cleanup() {
	
}