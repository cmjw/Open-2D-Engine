#include "Game.h"

Game::Game() {
    initialize();
}

Game::~Game() {
    cleanup();
}

void Game::initialize() {
    // Create the window
    window.create(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT), "Game Engine");

    // initialize Player?

    // Initialize the shape (a small rectangle, for example)
    //player.setSize(sf::Vector2f(50.f, 50.f));  // 50x50 pixel square
    //player.setFillColor(sf::Color::Green);     // Set the color of the shape
    //player.setPosition(GAME_WIDTH / 2, GAME_HEIGHT / 2);  // Start in the center of the screen

}

void Game::update(float deltaTime) {
    // Handle input to move the shape
    //float movementSpeed = 200.f;  // Pixels per second

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
    //window.draw(player);  // Render the shape
    player.draw(window);
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
