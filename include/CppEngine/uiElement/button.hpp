#pragma once

#include "uiElement.hpp"
#include "../imgui/imgui.h"
#include <string>
#include <functional>

namespace eng
{
    class Button: public UIElement
    {
    private:
        ImVec2 size;
        std::string label;
        std::function<void()> onPressed;

    public:
        Button(const std::string& label, const ImVec2& size = {0, 0});

        void setOnPressed(const std::function<void()>& onPressed);

        void render() override;

    private:
        bool renderDefaultSize();
        bool renderCustomSize();
    };
}
