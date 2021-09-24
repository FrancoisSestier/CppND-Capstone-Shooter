#pragma once
#include "SDL.h"

class Texture
{
public:
    Texture(const char *path);

    ~Texture();

    Texture(const Texture& texture) = delete;
    Texture(Texture&& texture);

    Texture& operator=(const Texture& texture) =delete;
    Texture& operator=(Texture&& texture);


    SDL_Texture *operator->();

    SDL_Texture &operator*();

private:
    void load_texture(const char *path);
    SDL_Texture *texture_ = nullptr;
};