#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <nlohmann/json.hpp>

#include "Game.h"

int main() {
    Game game;
    game.run();

    return 0;
}