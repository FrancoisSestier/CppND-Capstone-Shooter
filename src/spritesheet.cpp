#include "spritesheet.hpp"
#include <iostream>

Spritesheet::Spritesheet(std::shared_ptr<Texture> texture, uint32_t x_size, uint32_t y_size, uint32_t framecount) : x_size_{x_size}, framecount_{framecount}, texture_(std::move(texture)) {}

Spritesheet::Spritesheet(std::shared_ptr<Texture> texture, uint32_t framecount) : framecount_{framecount}, texture_(std::move(texture)) {}

Spritesheet::Spritesheet(Spritesheet &&other) : texture_{std::move(other.texture_)}, x_size_{other.x_size_}, framecount_{other.framecount_} {}

SDL_Rect Spritesheet::GetRect() const
{
    SDL_Rect clip;
    clip.x = 0;
    clip.y = texture_->GetHeight()/framecount_*current_sprite_frame_;
    clip.h = texture_->GetHeight()/framecount_;
    clip.w = texture_->GetWidth()/x_size_;
    return clip;
}

void Spritesheet::Tick() 
{
    tick_count++;
    current_sprite_frame_ = static_cast<int>(trunc(tick_count/60)) % framecount_;
}

void Spritesheet::Reset() 
{
    current_sprite_frame_ = 0;
    tick_count = 0;
}

bool Spritesheet::AnimationEnded() const{
    return current_sprite_frame_ >= framecount_-1;
}


SDL_Texture* Spritesheet::GetSDLTexture() const {
    return texture_->operator->();
}