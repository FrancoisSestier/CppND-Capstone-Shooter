#pragma once
#include <vec2.hpp>

struct Target {
    vec2 pos;
    vec2 speed;
    float width;
    float height;
};

class ITargetable
{
public:
    virtual ~ITargetable() = default;
    virtual Target GetTarget() const = 0;
};