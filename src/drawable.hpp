#pragma once
#include <SDL.h>
#include <camera.hpp>

class IDrawable
{
public:
    virtual ~IDrawable() = default;

    virtual void Draw(SDL_Renderer *renderer,const Camera* camera) const = 0;
};