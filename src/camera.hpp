#pragma once
#include "vec2.hpp"
#include <targetable.hpp>

class Camera {
public:
    Camera(ITargetable* target );
    vec2 GetPos() const;
    void Update();

private:
    ITargetable* target_;
    vec2 pos_{0,0};
    float dead_zone_ = 480;
    float hard_zone_ = 500;
    float soft_zone = 510;

};