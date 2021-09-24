#include "spritesheet.hpp"

Spritesheet::Spritesheet(std::shared_ptr<Texture> texture, uint32_t x_size, uint32_t y_size, uint32_t framecount) : x_size_{x_size}, y_size_{y_size}, framecount_{framecount}, texture_(std::move(texture)) {}

Spritesheet::Spritesheet(std::shared_ptr<Texture> texture, uint32_t framecount) :framecount_{framecount}, texture_(std::move(texture)), y_size_{framecount} {}


Spritesheet::Spritesheet(Spritesheet &&other) : texture_{std::move(other.texture_)},x_size_{other.x_size_}, y_size_{other.y_size_}, framecount_{other.framecount_} {}
