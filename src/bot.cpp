#include <bot.hpp>
#include <SDL.h>
#include <camera.hpp>

void Bot::Update()
{
    spritesheet_map_.at(state_).Tick();
    switch (state_)
    {
    case BotState::Dead:
        break;
    case BotState::Hit:
        if (GetSpritesheet().AnimationEnded())
        {
            SetState(BotState::Dead);
        }
        break;
    case BotState::Charging:
        speed_.x = target_->GetTarget().pos.x < pos_.x ? -.01f : .01f;
        if (GetSpritesheet().AnimationEnded())
        {
            SetState(BotState::Shooting);
            ShootTarget();
        }
        break;

    case BotState::Shooting:
        if (GetSpritesheet().AnimationEnded())
        {
            SetState(BotState::Idle);
        }
        break;
    case BotState::Moving:
        Move();
    default:
        if (TargetInRange())
        {
            SetState(BotState::Charging);
        }
        else
        {
            SetState(BotState::Moving);
        }
        break;
    }
}

vec2 Bot::GetPos() const
{
    return pos_;
}

BotState Bot::GetState() const
{
    return state_;
}

bool Bot::IsAlive() const
{
    return state_ != BotState::Dead;
}

const Spritesheet &Bot::GetSpritesheet() const
{
    return spritesheet_map_.at(state_);
}

void Bot::Draw(SDL_Renderer *renderer, const Camera *camera) const
{
    SDL_Rect srcrect = GetSpritesheet().GetRect();
    SDL_Rect dstrect = srcrect;
    dstrect.x = pos_.x - camera->GetPos().x;
    dstrect.y = pos_.y + camera->GetPos().y;
    dstrect.w = width_;
    dstrect.h = height_;

    SDL_RendererFlip flip = speed_.x >= 0 ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer, GetSpritesheet().GetSDLTexture(), &srcrect, &dstrect, 0, NULL, flip);
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

void Bot::OnCollision(ICollidable *other)
{
    SetState(BotState::Hit);
}

AABB Bot::GetAABB() const
{
    return AABB{vec2{(speed_.x >= 0) ? pos_.x + width_ / 2 + 5 : pos_.x + 20, pos_.y + 45}, vec2{width_ / 3, height_ / 3}};
}

vec2 Bot::GetSpeed() const
{
    return speed_;
}

collision_mask_t Bot::GetCollisionMask() const
{
    return CollisionLayer_Ennemy;
}

bool Bot::TargetInRange()
{
    return (target_ != nullptr) && (vec2_helper::distance(pos_, target_->GetTarget().pos) <= max_shooting_range_);
}

void Bot::Move()
{
    speed_ = vec2_helper::normalize(target_->GetTarget().pos - pos_);
    pos_ += speed_*max_speed;
}

void Bot::ShootTarget()
{
    vec2 bullet_pos = vec2{(speed_.x >= 0) ? pos_.x + width_ - 30 : pos_.x+10, pos_.y + height_ / 2-10};
    vec2 bullet_speed = vec2_helper::normalize(target_->GetTarget().pos - pos_) * shooting_force_;
    instanciate_bullet_(bullet_pos, bullet_speed);
}

void Bot::SetState(BotState state)
{
    if (state_ != state)
    {
        state_ = state;
        spritesheet_map_.at(state_).Reset();
    }
}

Bot::Bot(vec2 pos, const std::unordered_map<BotState, std::shared_ptr<Texture>> &bot_texture, ITargetable *target, bullet_callback instanciate_bullet) : pos_{pos}, target_{target}, instanciate_bullet_{instanciate_bullet}
{
    spritesheet_map_.emplace(BotState::Dead, Spritesheet{bot_texture.at(BotState::Dead), 3, 9, 9});
    spritesheet_map_.emplace(BotState::Hit, Spritesheet{bot_texture.at(BotState::Hit), 3, 5, 5});
    spritesheet_map_.emplace(BotState::Idle, Spritesheet{bot_texture.at(BotState::Idle), 3, 9, 9});
    spritesheet_map_.emplace(BotState::Moving, Spritesheet{bot_texture.at(BotState::Moving), 3, 4, 4});
    spritesheet_map_.emplace(BotState::Shooting, Spritesheet{bot_texture.at(BotState::Shooting), 3, 4, 4});
    spritesheet_map_.emplace(BotState::Charging, Spritesheet{bot_texture.at(BotState::Charging), 3, 9, 9});
}