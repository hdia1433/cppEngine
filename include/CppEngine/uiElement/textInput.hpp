#pragma once

#include "uiElement.hpp"
#include "CppEngine/components/label.hpp"

namespace eng
{
class TextInput: public eng::UIElement
{
private:
    Label label;

    std::string buffer;

public:
    TextInput(std::string_view label);

    std::string_view getBuffer();

    void render() override;
};
}
