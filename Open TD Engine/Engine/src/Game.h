#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    ~Game();

    void run();  // Main game loop

private:
    void initialize();  // Initialize game resources
    void update(float deltaTime);  // Update game state
    void render();  // Render the game
    void cleanup();  // Cleanup game resources

    sf::RenderWindow window;
    const int GAME_WIDTH = 800;
    const int GAME_HEIGHT = 600;

    // Add player as an sf::RectangleShape
    sf::RectangleShape player;
};

#endif // GAME_H
