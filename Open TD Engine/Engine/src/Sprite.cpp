#include "Sprite.h"

Sprite::Sprite() {}

Sprite::~Sprite() {}

Sprite::Sprite(sf::Texture& texture, int width, int height, int index) {
	this->width = width;
	this->height = height;

	sprite.setTexture(texture);

	int x = (index % (texture.getSize().x / width)) * width;
	int y = (index / (texture.getSize().x / width)) * height;

	sprite.setTextureRect(sf::IntRect(x, y, width, height));
}

void Sprite::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

void Sprite::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}