#pragma once

#include "uiElement.hpp"
#include <string>
#include "imgui.h"

namespace eng
{
    class PopupMenu: public UIElement
    {
    private:
        std::string label;
        bool inputBlocking;
        ImGuiWindowFlags flags;
    public:
        PopupMenu(const std::string& label, bool inputBlocking = true, ImGuiWindowFlags flags = 0);

        void render() override;

        virtual void popupRender() = 0;
    };
}
