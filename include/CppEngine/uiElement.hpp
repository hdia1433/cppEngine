#pragma once

namespace eng
{
class UIElement
{
public:
    enum class Alignment
    {
        Left,
        Right,
        Middle
    };

protected:
    Alignment alignment;

public:
    UIElement();
    virtual ~UIElement() = default;

    void setAlignment(const Alignment& alignment);

    virtual void render() = 0;
};
}
