#include "texture.hpp"
#include "renderer.hpp"
#include "SDL.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char *path)
{
    load_texture(path);
}

Texture::~Texture()
{
    if (texture_)
    {
        SDL_DestroyTexture(texture_);
    }
}

    Texture::Texture(Texture&& other) : texture_(other.texture_) {
        other.texture_ = nullptr;
    }

    Texture& Texture::operator=(Texture&& other) {
        if(texture_ != other.texture_) {
            texture_ = other.texture_;
            other.texture_ = nullptr;
        }
        return *this;
    }


void Texture::load_texture(const char *path)
{

    texture_ = IMG_LoadTexture(Renderer::GetInstance()->GetHandle(), path);
    if (texture_ == nullptr)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
    }
}

SDL_Texture *Texture::operator->() { return texture_; }

SDL_Texture &Texture::operator*() { return *texture_; }
