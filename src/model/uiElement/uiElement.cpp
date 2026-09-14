#include "CppEngine/uiElement/uiElement.hpp"

using namespace eng;

using Label = UIElement::Label;

Label::Label(std::string_view label): label(label)
{}

UIElement::UIElement()
{}

void UIElement::setAlignment(const Alignment& alignment)
{
    this->alignment = alignment;
}
