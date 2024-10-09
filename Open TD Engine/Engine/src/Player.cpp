#include "Player.h"

Player::Player() {
	initialize();
	
	// load spritesheet
}

Player::~Player() {

}

void Player::initialize() {
	loadPlayerData();

	sprite.setSize(sf::Vector2f(50.f, 50.f)); 
	sprite.setFillColor(sf::Color::Blue);    
	sprite.setPosition(0, 0); 

	movementSpeed = 200.f;
}

void Player::loadPlayerData() {
	// eventually this is saved as some "starting graphic"

	std::string jsonFile = "../Data/Player.json";

	std::ifstream file(jsonFile);

	if (!file.is_open()) {
		std::cerr << "Could not open file: " << jsonFile << std::endl;
		return;
	}
	/*nlohmann::json playerData;
	file >> playerData;*/

	//width = playerData["size"]["width"];
	//height = playerData["size"]["height"];
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