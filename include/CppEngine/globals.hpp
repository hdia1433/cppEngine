#pragma once

#include <string>

namespace eng
{
    class Globals
    {
    public:
        static bool running;
        static std::string currentScene;
        static float scale;
        static bool popupOpen;
    };
}
