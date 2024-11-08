#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Map.h"

#define CONFIG_FILE "./../Data/config.json"

class Game {
public:
    Game();
    ~Game();

    void run(); 

private:
    void initialize(); 
    void update(float deltaTime);  
    void render();  
    void cleanup();  

    void initializeGameWindow();
    void loadConfigFile();

    // display window
    sf::RenderWindow window;  
    sf::View view;

    // player
    Player player;

    // current map
    Map* gameMap;

    // game and window dimenstions
    int gameWidth;
    int gameHeight;
    float zoom;
    
    std::string game_title;
};

#endif // GAME_H
