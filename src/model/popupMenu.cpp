#include "popupMenu.hpp"

using namespace eng;

PopupMenu::PopupMenu(const std::string& label, bool inputBlocking, ImGuiWindowFlags flags):
    label(label),
    inputBlocking(inputBlocking),
    flags(flags)
{

}

void PopupMenu::render()
{
    if(ImGui::Begin(label.c_str(), nullptr, flags))
    {

    }
    ImGui::End();
}
