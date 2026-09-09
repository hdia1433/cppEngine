#include "popupMenu.hpp"
#include "globals.hpp"

using namespace eng;

PopupMenu::PopupMenu(const std::string& label, bool inputBlocking, ImGuiWindowFlags flags):
    label(label),
    inputBlocking(inputBlocking),
    flags(flags),
    visible(false)
{

}

void PopupMenu::setVisible(bool visible)
{
    this->visible = visible;

    Globals::popupOpen = visible;
}

