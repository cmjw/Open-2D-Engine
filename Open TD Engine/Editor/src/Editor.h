#ifndef EDITOR_H
#define EDITOR_H

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <windows.h>

class Editor {
public:
	Editor();
	~Editor();

	void run();

private:
	void initialize();
	void initMenubar();
	void render();
	
	void cleanup();

	const int EDITOR_WIDTH = 1200;
	const int EDITOR_HEIGHT = 1000;

	sf::RenderWindow window;
	
	sf::Clock deltaClock;

	bool isDarkMode;
};

#endif