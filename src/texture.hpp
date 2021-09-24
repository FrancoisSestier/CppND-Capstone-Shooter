#pragma once
#include "SDL.h"
#include <string>

class Texture
{
public:
    Texture(const char *path);
    Texture(const std::string& path);

    ~Texture();

    Texture(const Texture &texture) = delete;
    Texture(Texture &&texture);

    Texture &operator=(const Texture &texture) = delete;
    Texture &operator=(Texture &&texture);

    SDL_Texture *operator->();

    SDL_Texture &operator*();

    uint32_t GetWidth() const;
    uint32_t GetHeight() const;

private:
    void LoadTexture(const char *path);
    SDL_Texture *texture_ = nullptr;
    uint32_t width_;
    uint32_t height_;
};