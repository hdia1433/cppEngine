#include "CppEngine/uiElement/textInput.hpp"
#include "CppEngine/imgui/imgui.h"
#include "CppEngine/imgui/imgui_stdlib.h"

TextInput::TextInput(std::string_view label):
    label(label)
{}

std::string_view TextInput::getBuffer()
{
    return buffer;
}

void TextInput::render()
{
    label.render();

    ImGui::InputText(label.label.c_str(), &buffer);
}
