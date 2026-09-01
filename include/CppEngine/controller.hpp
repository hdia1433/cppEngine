#pragma once

#include <SFML/Graphics.hpp>
#include "imgui.h"

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
