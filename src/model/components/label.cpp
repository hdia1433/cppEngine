#include "CppEngine/components/label.hpp"
#include "CppEngine/imgui/imgui.h"

Label::Label(std::string_view label):
    label(label)
{}

void Label::render()
{
    if(label.substr(0, 2) == "##")
    {
        return;
    }

    ImGui::Text("%s", label.c_str());

    ImGui::SameLine();
}
