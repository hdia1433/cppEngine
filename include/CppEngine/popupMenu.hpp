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
        bool visible;

    protected:
    public:
        PopupMenu(const std::string& label, bool inputBlocking = true, ImGuiWindowFlags flags = 0);

        void setVisible(bool visible);
    };
}
