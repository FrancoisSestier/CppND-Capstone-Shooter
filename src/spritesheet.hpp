#pragma once
#include "texture.hpp"
#include <cstdint>
#include <memory>

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

    uint32_t FrameCount() const {return framecount_;}

private:
    uint32_t x_size_ = 1;
    uint32_t framecount_;
    uint32_t y_size_ ;

    SDL_Rect clip_;
    std::shared_ptr<Texture> texture_;
};