#pragma once
#include "texture.hpp"
#include "vec2.hpp"
#include <memory>
#include <drawable.hpp>
#include <SDL.h>
#include <camera.hpp>

class Prop : public IDrawable
{
public:
    Prop(vec2 pos, Texture *texture, bool flip, float scale = 4.5, float rotation = 0);

    void SetPos(vec2 pos);
    vec2 GetPos() const;
    Texture *GetTexture() const;
    bool GetFlip() const;
    void SetParallaxFactor();

    //IDrawable
    void Draw(SDL_Renderer* renderer,const Camera* camera ) const override;

private:
    vec2 pos_;
    Texture *texture_;
    float parallax_factor_;
    float rotation_{0};
    bool flip_;
    float scale_{4.5};
    float parallax_mod_;
};
