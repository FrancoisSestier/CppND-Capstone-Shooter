#include <camera.hpp>
#include <constants.hpp>

vec2 Camera::GetPos() const
{
    return pos_;
}

void Camera::Update()
{
    auto target_info = target_->GetTarget(); 
    if (target_info.pos.x <= (pos_.x + soft_zone))
    {
        pos_.x -= target_info.speed.x/10;
        if (target_info.pos.x <= (pos_.x + hard_zone_))
        {
            pos_.x -= target_info.speed.x/3 ;
            if (target_info.pos.x <= (pos_.x + dead_zone_))
            {
                pos_.x-= target_info.speed.x;
                return;
            }
        }
    }
    else if (target_info.pos.x >= (pos_.x + _screen_width - soft_zone - target_info.width))
    {
        pos_.x += target_info.speed.x/10;
        if (target_info.pos.x >= (pos_.x + _screen_width - hard_zone_ - target_info.width))
        {
            pos_.x += target_info.speed.x/3;
            if (target_info.pos.x >= (pos_.x + _screen_width - dead_zone_ - target_info.width))
            {
                pos_.x+= target_info.speed.x;
            }
        }
    }
}

Camera::Camera(ITargetable* target) : target_{target}
{
    
}
