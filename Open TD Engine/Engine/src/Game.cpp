#include "Game.h"

Game::Game() {
    initialize();
}

Game::~Game() {
    cleanup();
}

void Game::initialize() {
    // Create the window
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game");

    // initialize Player?

    
    if (!testSpriteTexture.loadFromFile("./../Data/spritesheet.png")) {
        exit(-1);
    }

    testSprite = Sprite(testSpriteTexture, 60, 112, 1);
    testSprite.setPosition(0, 10);
}

void Game::update(float deltaTime) {
    // menu event
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        // draw menu
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        player.move(0, -1, deltaTime);  // Move up
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        player.move(0, 1, deltaTime);   // Move down
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.move(-1, 0, deltaTime);  // Move left
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.move(1, 0, deltaTime);   // Move right
    }
}

void Game::render() {
    window.clear();
    player.render(window);
    testSprite.draw(window);
    window.display();
}

void Game::cleanup() {
    // Cleanup resources
    
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}
