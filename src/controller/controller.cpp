#include "controller.hpp"
#include "globals.hpp"
#include <imgui-SFML.h>

using namespace eng;

Controller::Controller(const sf::Vector2u& windowSize):
    window(sf::VideoMode(windowSize), "game"),
    windowSize(800, 800),
    windowPos(0, 0)
{
    if(!ImGui::SFML::Init(window))
    {
        throw std::runtime_error("Failed to run ImGui::SFML::Init");
    }
}

Controller::~Controller()
{
    window.close();
    ImGui::SFML::Shutdown();

    for(auto& [_, scene]: scenes)
    {
        delete scene;
    }

    scenes.clear();
}

void Controller::render()
{
    while (window.isOpen() && Globals::running)
    {
        while(const std::optional<sf::Event> event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>())
            {
                Globals::running = false;
            }
            else if(const auto& resized = event->getIf<sf::Event::Resized>())
            {
                sf::Vector2u size = resized->size;

                float scaleX = size.x / windowSize.x;
                float scaleY = size.y / windowSize.y;

                Globals::scale *= std::min(scaleX, scaleY);

                if(size.x >= size.y)
                {
                    windowSize = {(float)size.y, (float)size.y};
                }
                else
                {
                    windowSize = {(float)size.x, (float)size.x};
                }

                windowPos = {(size.x - windowSize.x) / 2, (size.y - windowSize.y) / 2};
            }
        }

        sf::Time delta = deltaClock.reset();

        if(delta <= sf::Time::Zero)
        {
            delta = sf::seconds(1.f / 60);
        }

        ImGui::SFML::Update(window, delta);

        window.clear();

        ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);
        ImGui::SetNextWindowSize(windowSize, ImGuiCond_Always);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);

        ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;

        if(ImGui::Begin("##window", nullptr, windowFlags))
        {
            ImGui::SetWindowFontScale(Globals::scale);

            scenes[Globals::currentScene]->render();

            ImGui::SetWindowFontScale(Globals::scale);
        }
        ImGui::End();
        ImGui::PopStyleVar();

        ImGui::SFML::Render(window);
        window.display();
    }
}

void Controller::addScene(const std::string& name, Scene* scene)
{
    scenes.emplace(name, scene);
}
