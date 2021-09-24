#include "texture.hpp"
#include "renderer.hpp"
#include "SDL.h"
#include <SDL2/SDL_image.h>

Texture::Texture(const char *path)
{
    LoadTexture(path);
}

Texture::~Texture()
{
    if (texture_)
    {
        SDL_DestroyTexture(texture_);
    }
}

Texture::Texture(Texture &&other) : texture_(other.texture_)
{
    other.texture_ = nullptr;
}

Texture::Texture(const std::string& path) 
{
    LoadTexture(path.c_str());
}

Texture &Texture::operator=(Texture &&other)
{
    if (texture_ != other.texture_)
    {
        texture_ = other.texture_;
        other.texture_ = nullptr;
    }
    return *this;
}

void Texture::LoadTexture(const char *path)
{

    //Load image at specified path
    SDL_Surface *surface = IMG_Load(path);
    if (surface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        texture_ = SDL_CreateTextureFromSurface(Renderer::GetInstance()->GetHandle(), surface);
        if (texture_ == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
        }
        height_ = surface->h;
        width_ = surface->w;
        //Get rid of old loaded surface
        SDL_FreeSurface(surface);
    }
}

SDL_Texture *Texture::operator->() { return texture_; }

uint32_t Texture::GetWidth() const
{
    return width_;
}

uint32_t Texture::GetHeight() const
{
    return height_;
}

SDL_Texture &Texture::operator*() { return *texture_; }
