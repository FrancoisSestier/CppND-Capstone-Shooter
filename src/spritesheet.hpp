#pragma once
#include "texture.hpp"
#include <cstdint>
#include <memory>
#include <SDL.h>

class Spritesheet
{
public:
    Spritesheet(std::shared_ptr<Texture> texture, uint32_t framecount);
    Spritesheet(std::shared_ptr<Texture> texture, uint32_t x_size, uint32_t y_size, uint32_t framecount);
    ~Spritesheet() = default;

    Spritesheet(const Spritesheet &other) = delete;
    Spritesheet(Spritesheet &&other);
    Spritesheet &operator=(const Spritesheet &other) = delete;
    Spritesheet &operator=(Spritesheet &&other);

    SDL_Texture *GetSDLTexture() const;

    uint32_t GetFrameCount() const { return framecount_; }
    bool AnimationEnded() const;
    SDL_Rect GetRect() const;

    void Tick();

    void Reset();

private:
    uint32_t current_sprite_frame_ {0};
    float tick_count {0};
    uint32_t x_size_ = 1;
    uint32_t framecount_;
    std::shared_ptr<Texture> texture_;
};