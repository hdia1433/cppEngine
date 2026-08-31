#include "controller.hpp"
#include "globals.hpp"
#include <imgui-SFML.h>

using namespace eng;

Controller::Controller()
{
    if(!ImGui::SFML::Init(window))
    {
        throw std::runtime_error("Failed to run ImGui::SFML::Init");
    }
}

void Controller::render()
{
    while (window.isOpen() && Globals::running)
    {
        while(const std::optional<sf::Event> event = window.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
            {
                Globals::running = false;
            }
            else if(const auto& resized = event->getIf<sf::Event::Resized>())
            {
                windowSize = {(float)resized->size.x, (float)resized->size.y};
            }
        }

        sf::Time delta = deltaClock.reset();

        if(delta <= sf::Time::Zero)
        {
            delta = sf::seconds(1.f / 60);
        }

        ImGui::SFML::Update(window, delta);

        window.clear();

        ImGui::SetNextWindowPos({0.f, 0.f}, ImGuiCond_Always);
        ImGui::SetNextWindowSize(windowSize, ImGuiCond_Once);

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;

        if(ImGui::Begin("##window", nullptr, windowFlags))
        {

        }
        ImGui::End();

        ImGui::SFML::Render(window);
        window.display();
    }

    window.close();
    ImGui::SFML::Shutdown();
}
