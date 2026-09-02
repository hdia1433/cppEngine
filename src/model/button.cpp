#include "button.hpp"
#include "globals.hpp"

using namespace eng;

Button::Button(const std::string& label, const ImVec2& size):
    label(label),
    size(size)
{

}

void Button::setOnPressed(const std::function<void()>& onPressed)
{
    this->onPressed = onPressed;
}

void Button::render()
{
    bool pressed = false;

    if(size.x == 0.f && size.y == 0.f)
    {
        pressed = renderDefaultSize();
    }
    else
    {
        pressed = renderCustomSize();
    }

    if(pressed)
    {
        onPressed();
    }
}

bool Button::renderDefaultSize()
{
    if(Alignment::Left == alignment)
    {
        return ImGui::Button(label.c_str());
    }

    float buttonWidth = ImGui::CalcTextSize(label.c_str()).x + ImGui::GetStyle().FramePadding.x;
    float availableWidth = ImGui::GetContentRegionAvail().x;

    if(Alignment::Centre == alignment)
    {
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (availableWidth + buttonWidth) / 2);

        return ImGui::Button(label.c_str());
    }

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + availableWidth - buttonWidth);

    return ImGui::Button(label.c_str());
}

bool Button::renderCustomSize()
{
    ImVec2 scaledSize = {size.x * Globals::scale, size.y * Globals::scale};

    if(Alignment::Left == alignment)
    {
        return ImGui::Button(label.c_str(), scaledSize);
    }

    float availableWidth = ImGui::GetContentRegionAvail().x;

    if(Alignment::Centre == alignment)
    {
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (availableWidth - size.x) / 2);

        return ImGui::Button(label.c_str(), scaledSize);
    }

    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + availableWidth - size.x);

    return ImGui::Button(label.c_str(), scaledSize);
}
