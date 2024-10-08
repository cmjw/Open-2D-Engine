#ifndef EDITOR_H
#define EDITOR_H

#include <SFML/Graphics.hpp>

class Editor {
public:
	Editor();
	~Editor();

private:
	void initialize();
	void initMenubar();

	const int EDITOR_WIDTH = 1200;
	const int EDITOR_HEIGHT = 1000;
	sf::RenderWindow window;
};

#endif