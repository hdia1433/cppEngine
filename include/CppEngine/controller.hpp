#pragma once

#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "scene.hpp"

namespace eng
{
    class Controller
    {
    private:
        sf::RenderWindow window;
        sf::Clock deltaClock;
        ImVec2 windowSize;
        ImVec2 windowPos;
        std::unordered_map<std::string, Scene*> scenes;

    public:
        Controller(const sf::Vector2u& windowSize);
        ~Controller();
        void render();

        void addScene(const std::string& name, Scene* scene);
    };
}
