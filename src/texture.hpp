#pragma once
#include "SDL.h"
#include <string>

class Texture
{
public:
    Texture(const char *path);
    Texture(SDL_Surface* surface);
    Texture(const std::string& path,bool is_flat = false);

    ~Texture();

    Texture(const Texture &texture) = delete;
    Texture(Texture &&texture);

    Texture &operator=(const Texture &texture) = delete;
    Texture &operator=(Texture &&texture);

    SDL_Texture *operator->();

    SDL_Texture &operator*();

    SDL_Texture *GetHandle();

    uint32_t GetWidth() const;
    uint32_t GetHeight() const;
    SDL_Rect GetRect() const;
    bool IsFlat() const;

private:
    void LoadTexture(const char *path);
    SDL_Texture *texture_ = nullptr;
    uint32_t width_;
    uint32_t height_;
    bool is_flat_;
};