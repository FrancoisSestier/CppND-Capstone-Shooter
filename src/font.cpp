#include <font.hpp>
#include <SDL2/SDL_ttf.h>
#include <iostream>

Font::Font(const char *path, int size)
{
    font_ = TTF_OpenFont(path, size);
    if(!font_){
        std::cerr << TTF_GetError() << std::endl;
    }
}

Font::Font(Font &&other) : font_(other.font_)
{
}

Font &Font::operator=(Font &&other)
{
    if (font_ != other.font_)
    {
        font_ = other.font_;
        other.font_ = nullptr;
    }
    return *this;
}

std::unique_ptr<Texture> Font::TextToTexture(const char *text, SDL_Color color) const
{

    SDL_Surface *surface =
        TTF_RenderText_Solid(font_, text, color);
    return std::move(std::make_unique<Texture>(surface));
}

TTF_Font *Font::operator->()
{
    return font_;
}

TTF_Font &Font::operator*()
{
    return *font_;
}

Font::~Font()
{
    if (font_ != nullptr)
    {
        TTF_CloseFont(font_);
    }
}
