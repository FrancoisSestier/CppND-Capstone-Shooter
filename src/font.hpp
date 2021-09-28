#pragma once
#include "SDL2/SDL_ttf.h"
#include <string>
#include <texture.hpp>
#include <memory>

class Font
{
public:
    Font(const char *path, int size);
    Font(const std::string& path,int size);

    ~Font();

    Font(const Font &other) = delete;
    Font(Font &&other);

    Font &operator=(const Font &other) = delete;
    Font &operator=(Font &&other);

    std::unique_ptr<Texture> TextToTexture(const char* text, SDL_Color color) const;

    TTF_Font *operator->();

    TTF_Font &operator*();

    uint32_t GetSize() const;

private:
    TTF_Font* font_ = nullptr;
    uint32_t width_;
    uint32_t height_;
    bool is_flat_;
};

