#pragma once

#define IMGUI_DEFINE_MATH_OPERATIONS

#include <SFML/Graphics.hpp>
#include <imgui.h>

namespace eng
{
class Controller
{
private:
    sf::RenderWindow window;
    sf::Clock deltaClock;

    ImVec2 windowSize;

public:
    Controller();

    void render();
};
}
