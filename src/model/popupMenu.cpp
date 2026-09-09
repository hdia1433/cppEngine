#include "popupMenu.hpp"
#include "globals.hpp"

using namespace eng;

PopupMenu::PopupMenu(bool inputBlocking):
    inputBlocking(inputBlocking),
    visible(false)
{

}

void PopupMenu::setVisible(bool visible)
{
    this->visible = visible;

    if(inputBlocking)
    {
        Globals::popupOpen = visible;
    }
}

