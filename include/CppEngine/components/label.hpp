#pragma once

#include <string>

struct Label
{
    std::string label;

    Label(std::string_view label);

    void render();
};
