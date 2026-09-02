#pragma once

namespace eng
{
    class Scene
    {
    public:
        virtual ~Scene() = default;

        virtual void render() = 0;
    };
}
