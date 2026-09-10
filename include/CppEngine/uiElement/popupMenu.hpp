#pragma once

#include "uiElement.hpp"
#include "../imgui/imgui.h"
#include <functional>
#include <string>

namespace eng
{
    class PopupMenu: public UIElement
    {
    private:
        std::string label;
        bool modal;
        ImGuiWindowFlags flags;

    protected:
        std::function<void()> renderMenu;

    public:
        PopupMenu(std::string_view label, bool modal);
        PopupMenu(std::string_view label, ImGuiWindowFlags flags = 0);

        void setRenderMenu(const std::function<void()>& renderMenu);

        void render() override;
        void open();
    };
}
