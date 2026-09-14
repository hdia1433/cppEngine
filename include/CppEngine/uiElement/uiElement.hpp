#pragma once

#include <string>

namespace eng
{
class UIElement
{
public:
    enum class Alignment
    {
        Left,
        Right,
        Centre
    };

    class Label
    {
    private:
        std::string label;

    public:
        Label(std::string_view label);
    };

protected:
    Alignment alignment;

public:
    UIElement();
    virtual ~UIElement() = default;

    void setAlignment(const Alignment& alignment);

    virtual void render() = 0;
};
} // namespace eng
