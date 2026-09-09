#pragma once

#include "uiElement.hpp"

namespace eng
{
    class PopupMenu: public UIElement
    {
    private:
        bool inputBlocking;
        bool visible;

    protected:
    public:
        PopupMenu(bool inputBlocking = true);

        bool& getVisible();
        void setVisible(bool visible);
    };
}
