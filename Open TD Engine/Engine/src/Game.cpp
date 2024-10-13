#include "Game.h"

Game::Game() {
    initialize();
}

Game::~Game() {
    cleanup();
}

/* Initialize game elements */
void Game::initialize() {
    loadConfigFile();

    initializeGameWindow();

    gameMap = new Map(4, 3, "./../Data/tileset.png");

    // test tile
    //testShape.setSize(sf::Vector2f(16.f, 16.f));  // A tile is 16x16 pixels
    //testShape.setFillColor(sf::Color::Green);
    //testShape.setPosition(gameWidth / 2 - 8, gameHeight / 2 - 8); // Center the shape
}

/* Load config file. */
void Game::loadConfigFile() {
    std::ifstream file(CONFIG_FILE);

    if (file.is_open()) {
        nlohmann::json config;

        try {
            file >> config;
        } catch (const json::parse_error& e) {
            std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
            file.close();
        } catch (const std::exception& e) {
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

/* Initialize the game and virtualized view window. Dimensions are obtained from config.json */
void Game::initializeGameWindow() {
    // create window
    window.create(sf::VideoMode(gameWidth * zoom, gameHeight * zoom), "Game");

    view.setSize(gameWidth, gameHeight);
    view.setCenter(gameWidth / 2, gameHeight / 2);

    // set zoom
    view.zoom(zoom/2);
    window.setView(view);
}

void Game::update(float deltaTime) {
    player.updateMovement(deltaTime);
}

void Game::render() {
    window.clear();

    //window.draw(testShape); // test tile size

    gameMap->render(window);

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
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}
