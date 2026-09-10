#pragma once

#include <initializer_list>

namespace eng
{
    template<typename T>
    bool equalsOr(T thing, std::initializer_list<T> others)
    {
        for(const T& otherThing: others)
        {
            if(thing == otherThing)
            {
                return true;
            }
        }

        return false;
    }
}
