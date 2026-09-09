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

        void setVisible(bool visible);
    };
}
