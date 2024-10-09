#include "Player.h"

using json = nlohmann::json;

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {

}

void Player::initialize() {
	if (!loadPlayerData()) {
		// throw error
	}

	sprite.setSize(sf::Vector2f(width, height)); 
	sprite.setFillColor(sf::Color::Blue);    
	sprite.setPosition(0, 0); 

	movementSpeed = 200.f;
}

bool Player::loadPlayerData() {
	// eventually this is saved as some "starting graphic"

	std::string jsonFile = "../Data/Player.json";

	std::ifstream file(jsonFile);

	if (!file.is_open()) {
		std::cerr << "Could not open file: " << jsonFile << std::endl;
		return false;
	}

	json playerData;

	try {
		file >> playerData;  // This can throw if the JSON is invalid
	}
	catch (const json::parse_error& e) {
		std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
		return false;
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		return false;
	}

	file.close();

	width = playerData["size"]["width"];
	height = playerData["size"]["height"];

	return true;
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void Player::move(float dx, float dy, float deltaTime) {
	float newX = dx * movementSpeed * deltaTime;
	float newY = dy * movementSpeed * deltaTime;

	// collisions?

	sprite.move(newX, newY);
}