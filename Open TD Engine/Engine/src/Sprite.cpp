#include "Sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(sf::Texture& texture, int width, int height, int index) {
	this->width = width;
	this->height = height;

	sprite.setTexture(texture);

	int w = width / 3;
	int h = height / 4;

	//sprite.setTextureRect(sf::IntRect(2*w,0,3*w,2*h));
	//sprite.setTextureRect(sf::IntRect(0, 0, width, height));
}

Sprite::~Sprite() {}

void Sprite::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

void Sprite::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}