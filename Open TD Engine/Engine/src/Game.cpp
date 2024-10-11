#include "Game.h"

Game::Game() {
    initialize();
}

Game::~Game() {
    cleanup();
}

void Game::initialize() {
    loadConfigFile();

    initializeGameWindow();

    // initialize Player?
}

void Game::loadConfigFile() {
    std::ifstream file("./../Data/config.json");

    if (file.is_open()) {
        nlohmann::json config;

        try {
            file >> config;
        }
        catch (const json::parse_error& e) {
            std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
            file.close();
        }
        catch (const std::exception& e) {
            std::cerr << "An error occurred: " << e.what() << std::endl;
            file.close();
        }

        gameWidth = config["game_width"];
        gameHeight = config["game_height"];
        zoom = config["zoom"];
    }
    else {
        std::cerr << "Could not open config file. Using default settings.\n";
        gameWidth = 640;
        gameHeight = 480;
    }
}

void Game::initializeGameWindow() {
    window.create(sf::VideoMode(gameWidth * zoom, gameHeight * zoom), "Game");

    view.setSize(gameWidth, gameHeight);
    view.setCenter(gameWidth / 2, gameHeight / 2);
    view.zoom(zoom/2);

    window.setView(view);
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
