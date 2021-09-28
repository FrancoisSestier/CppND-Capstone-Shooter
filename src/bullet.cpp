#include <bullet.hpp>
#include <SDL.h>
#include <camera.hpp>
#include <math.h>
#include <iostream>

Bullet::Bullet(vec2 pos, vec2 speed, Texture *texture, float width, float height, collision_mask_t collision_mask) : collision_mask_{collision_mask}, pos_{pos}, speed_{speed}, texture_{texture}, width_{width}, height_{height}
{
}

void Bullet::Update()
{
    pos_ += speed_;
}

vec2 Bullet::GetPos() const
{
    return pos_;
}

float Bullet::GetWidth() const
{
    return width_;
}

float Bullet::GetHeight() const
{
    return height_;
}

bool Bullet::IsActive() const
{
    return active_;
}

void Bullet::Draw(SDL_Renderer *renderer, const Camera *camera) const
{
    SDL_Rect srcrect = texture_->GetRect();
    SDL_Rect dstrect;
    dstrect.x = pos_.x - camera->GetPos().x;
    dstrect.y = pos_.y + camera->GetPos().y;
    dstrect.w = width_;
    dstrect.h = height_;
    float angle = atan2(speed_.y,speed_.x) * 180/M_PI;
    //angle = speed_.y >= 0 ? angle : - angle;
    SDL_RenderCopyEx(renderer, texture_->operator->(), &srcrect, &dstrect, angle, NULL, SDL_FLIP_NONE);
#ifndef NDEBUG
    SDL_Rect box;
    AABB ab = GetAABB();
    box.x = ab.pos.x - camera->GetPos().x;
    box.y = ab.pos.y;
    box.w = ab.extent.x;
    box.h = ab.extent.y;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &box);
#endif
}

void Bullet::OnCollision(ICollidable *other)
{
    active_ = false;
}

AABB Bullet::GetAABB() const
{
    return AABB{pos_, vec2{width_, height_}};
}

vec2 Bullet::GetSpeed() const
{
}

collision_mask_t Bullet::GetCollisionMask() const 
{
    return collision_mask_;
}
