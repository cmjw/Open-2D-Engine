#ifndef GAME_H
#define GAME_H

#include "Player.h"

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 720

#define GAME_WIDTH 320
#define GAME_HEIGHT 240

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
    sf::View view;
};

#endif // GAME_H
