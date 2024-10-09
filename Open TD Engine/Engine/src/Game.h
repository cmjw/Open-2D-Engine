#ifndef GAME_H
#define GAME_H

#include "Player.h"

#define GAME_WIDTH 800
#define GAME_HEIGHT 600

class Game {
public:
    Game();
    ~Game();

    void run();  // Main game loop

    Player player;

private:
    void initialize();  // Initialize game resources
    void update(float deltaTime);  // Update game state
    void render();  // Render the game
    void cleanup();  // Cleanup game resources

    sf::RenderWindow window;
    
    //sf::RectangleShape player;

    
};

#endif // GAME_H
