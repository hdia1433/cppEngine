#include "popupMenu.hpp"

using namespace eng;

PopupMenu::PopupMenu(std::string_view label, bool modal):
    label(label),
    modal(modal),
    flags(0)
{

}

PopupMenu::PopupMenu(std::string_view label, ImGuiWindowFlags flags):
    label(label),
    modal(false),
    flags(flags)
{

}

void PopupMenu::setRenderMenu(const std::function<void()>& renderMenu)
{
    this->renderMenu = renderMenu;
}

void PopupMenu::render()
{
    if((modal && ImGui::BeginPopupModal(label.c_str()) || (!modal && ImGui::BeginPopup(label.c_str(), flags))))
    {
        renderMenu();
        ImGui::EndPopup();
    }
}

void PopupMenu::open()
{
    ImGui::OpenPopup(label.c_str());
}
