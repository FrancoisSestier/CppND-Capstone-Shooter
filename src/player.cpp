#include <player.hpp>
#include <cmath>
#include <iostream>
#include <constants.hpp>

inline const std::string player_texture_folder{texture_folder + "/player"};
inline const std::string player_move_spritesheet{player_texture_folder + "/move without FX.png"};
inline const std::string player_move_fx__spritesheet{player_texture_folder + "/move FX.png"};

inline const std::string player_charge_spritesheet{player_texture_folder + "/charge.png"};
inline const std::string player_dash_spritesheet{player_texture_folder + "/GAS dash with FX.png"};
inline const std::string player_shoot_spritesheet{player_texture_folder + "/shoot with FX.png"};
inline const std::string player_Idle_spritesheet{player_texture_folder + "/static idle.png"};
inline const std::string player_death_spritesheet{player_texture_folder + "/death.png"};
inline const std::string player_wake_spritesheet{player_texture_folder + "/wake.png"};
inline const std::string player_damaged_texture_file{player_texture_folder + "/damaged.png"};
inline const std::string player_dead_texture_file{player_texture_folder + "/dead.png"};

inline const std::string player_bullet_texture_file{bullets_folder + "/bullet1.png"};

Player::Player(bullet_callback instanciate_bullet) : instanciate_bullet_{instanciate_bullet}
{
    LoadResource();
}

void Player::Update()
{
    spritesheet_map_.at(state_).Tick();

    switch (state_)
    {
    case PlayerState::Shooting:
        Move();

        if (GetSpritesheet().AnimationEnded())
        {
            if (moving_right_ || moving_left_)
            {
                SetState(PlayerState::Moving);
            }
            else
            {
                SetState(PlayerState::Idle);
            }
        }
        break;
    case PlayerState::Charging:
        Move();
        if (charge_ < 1)
        {
            charge_ += 0.02f;
        }
        break;
    case PlayerState::Dying:
        if (GetSpritesheet().AnimationEnded())
        {
            SetState(PlayerState::Dead);
        }
        break;
    case PlayerState::Waking:
    case PlayerState::Hit:
        if (GetSpritesheet().AnimationEnded())
        {
            SetState(PlayerState::Moving);
        }

    case PlayerState::Moving:
        Move();
        if (speed_.x == 0 && speed_.y == 0)
        {
            dead_frames_++;
        }
        else
        {
            dead_frames_ = 0;
        }
        if (dead_frames_ > max_dead_frames_)
        {
            SetState(PlayerState::Idle);
        }
        break;
    case PlayerState::Idle:
        if (moving_right_ != moving_left_ || moving_up_ != moving_down_)
        {
            SetState(PlayerState::Waking);
        }
        break;
    default:
        break;
    }
}

PlayerState Player::GetState() const
{
    return state_;
}

void Player::SetState(PlayerState state)
{
    if (state_ != state)
    {
        state_ = state;
        spritesheet_map_.at(state_).Reset();
        state_framecount_ = 0;
        dead_frames_ = 0;
    }
}

void Player::IncreaseFrameCount()
{
}

void Player::OnKey(KeyEvent e)
{
    ProcessKeyEventMoving(e);
    ProcessKeyEventShooting(e);
}

void Player::SetDir(Key key)
{
    switch (key)
    {
    case Key::Left:
        SetDir(Dir::Left);
        break;
    case Key::Right:
        SetDir(Dir::Right);
        break;
    default:
        break;
    }
}

void Player::SetDir(Dir dir)
{
    facing_dir_ = dir;
}

void Player::Move()
{
    speed_ = vec2{0, 0};
    if (moving_left_ != moving_right_)
    {
        if (moving_left_)
        {
            speed_.x = -max_speed;
        }
        if (moving_right_)
        {
            speed_.x = +max_speed;
        }
    }
    if (moving_up_ != moving_down_)
    {
        if (moving_down_)
        {
            speed_.y = max_speed;
        }
        if (moving_up_)
        {
            speed_.y = -max_speed;
        }
    }
    pos_ += speed_;
    if (pos_.y + GetAABB().extent.y - 40 < _foreground_level)
    {
        pos_.y = _foreground_level - GetAABB().extent.y + 40;
    }
    if (pos_.y + GetAABB().extent.y > _screen_height)
    {
        pos_.y = _screen_height - GetAABB().extent.y;
    }
}

void Player::Reset()
{
    score_ = 0;
    health_ = 100;
    SetState(PlayerState::Idle);
}


uint32_t Player::GetStateFramecount() const
{
    return state_framecount_;
}

void Player::LoadResource()
{

    spritesheet_map_.try_emplace(PlayerState::Moving, Spritesheet{std::make_shared<Texture>(player_move_spritesheet), 3, 8, 8});
    spritesheet_map_.try_emplace(PlayerState::Idle, Spritesheet{std::make_shared<Texture>(player_Idle_spritesheet), 3, 1, 1});
    spritesheet_map_.try_emplace(PlayerState::Dashing, Spritesheet{std::make_shared<Texture>(player_dash_spritesheet), 1});
    spritesheet_map_.try_emplace(PlayerState::Dying, Spritesheet{std::make_shared<Texture>(player_death_spritesheet), 3, 6, 6});
    spritesheet_map_.try_emplace(PlayerState::Shooting, Spritesheet{std::make_shared<Texture>(player_shoot_spritesheet), 3, 4, 4});
    spritesheet_map_.try_emplace(PlayerState::Charging, Spritesheet{std::make_shared<Texture>(player_charge_spritesheet), 3, 4, 4});
    spritesheet_map_.try_emplace(PlayerState::Waking, Spritesheet{std::make_shared<Texture>(player_wake_spritesheet), 3, 5, 5});
    spritesheet_map_.try_emplace(PlayerState::Hit, Spritesheet{std::make_shared<Texture>(player_damaged_texture_file), 3, 2, 2});
    spritesheet_map_.try_emplace(PlayerState::Dead, Spritesheet{std::make_shared<Texture>(player_dead_texture_file), 3, 1, 1});

    move_fx_ = std::make_unique<Spritesheet>(std::make_shared<Texture>(player_move_fx__spritesheet), 3, 8, 8);
    bullet_texture_ = std::make_unique<Texture>(player_bullet_texture_file.c_str());
}

const Spritesheet &Player::GetSpritesheet() const
{
    return spritesheet_map_.at(state_);
}

const Spritesheet *Player::GetMoveFX() const
{
    return move_fx_.get();
}

bool Player::Moving() const
{
    return moving_left_ != moving_right_;
}

vec2 Player::GetPos() const
{
    return pos_;
}

Dir Player::GetFacingDir() const
{
    return facing_dir_;
}

Dir Player::GetMoveDir() const
{
    if (!Moving())
    {
        return Dir::None;
    }
    return moving_left_ == true ? Dir::Left : Dir::Right;
}

float Player::GetWidth() const
{
    return width_;
}

float Player::GetHeight() const
{
    return height_;
}

int Player::GetScore() const
{
    return score_;
}

int Player::GetHealth() const
{
    return health_;
}

bool Player::IsAlive() const
{
    return state_ != PlayerState::Dead;
}

void Player::IncreaseScore(int to_add)
{
    score_ += to_add;
}

vec2 Player::GetSpeed() const
{
    return speed_;
}

AABB Player::GetAABB() const
{
    vec2 pos = facing_dir_ == Dir::Left ? vec2{pos_.x + 40, pos_.y + 20} : vec2{pos_.x + 70, pos_.y + 20};
    return AABB{pos, vec2{width_ / 3, height_}};
}

void Player::OnCollision(ICollidable *other)
{
    if (IsAlive())
    {
        health_ -= state_ == PlayerState::Idle ? 30 : 90;
        health_ >= 0 ? SetState(PlayerState::Hit) : SetState(PlayerState::Dying);
    }
}

collision_mask_t Player::GetCollisionMask() const
{
    return CollisionLayer_Player;
}

void Player::Draw(SDL_Renderer *renderer, const Camera *camera) const
{
    SDL_Rect srcrect = GetSpritesheet().GetRect();
    SDL_Rect dstrect = srcrect;
    dstrect.x = pos_.x - camera->GetPos().x;
    dstrect.y = pos_.y + camera->GetPos().y;
    dstrect.w *= scale_;
    dstrect.h *= scale_;

    SDL_RendererFlip flip = (facing_dir_ == Dir::Right) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer, GetSpritesheet().GetSDLTexture(), &srcrect, &dstrect, 0, NULL, flip);

    Dir moving_dir = GetMoveDir();
    if (moving_dir != Dir::None)
    {
        if (moving_dir != facing_dir_)
        {
            dstrect.x += (moving_dir == Dir::Right) ? -25 : 25; // Offset fx
        }
        SDL_RendererFlip flip_fx = (moving_dir == Dir::Right) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
        SDL_RenderCopyEx(renderer, GetMoveFX()->GetSDLTexture(), &srcrect, &dstrect, 0, NULL, flip_fx);
    }
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

Target Player::GetTarget() const
{
    return Target{pos_, max_speed, 0, width_, height_};
}

void Player::ProcessKeyEventMoving(KeyEvent e)
{

    if (e.key_state == KeyState::pressed && IsAlive() && state_ != PlayerState::Dying && state_ != PlayerState::Hit)
    {

        SetDir(e.key);

        switch (e.key)
        {
        case Key::Right:
            moving_right_ = true;
            break;
        case Key::Left:
            moving_left_ = true;
            break;
        case Key::Up:
            moving_up_ = true;
            break;
        case Key::Down:
            moving_down_ = true;
            break;
        default:
            break;
        }
    }
    else if (e.key_state == KeyState::released)
    {
        switch (e.key)
        {
        case Key::Right:
            moving_right_ = false;
            break;
        case Key::Left:
            moving_left_ = false;
            break;
        case Key::Up:
            moving_up_ = false;
            break;
        case Key::Down:
            moving_down_ = false;
            break;
        default:
            break;
        }
    }
}

void Player::ProcessKeyEventShooting(KeyEvent e)
{
    if (e.key_state == KeyState::pressed && e.key == Key::Space && IsAlive() && state_ != PlayerState::Dying && state_ != PlayerState::Hit)
    {
        SetState(PlayerState::Charging);
    }
    else if (e.key_state == KeyState::released && e.key == Key::Space && IsAlive() && state_ != PlayerState::Dying && state_ != PlayerState::Hit)
    {
        SetState(PlayerState::Shooting);
        Shoot();
    }
}

void Player::Shoot()
{
    float bullet_speed = facing_dir_ == Dir::Right ? max_speed : -max_speed;
    float bullet_width_ = 5 + charge_ * 50;
    float bullet_height_ = 10 + charge_ * 40;
    vec2 rifle_offset{width_, height_ / 2 - 8};
    vec2 rifle_pos = facing_dir_ == Dir::Right ? vec2{pos_.x + rifle_offset.x, pos_.y + rifle_offset.y - bullet_height_ / 2} : vec2{pos_.x - 20, pos_.y + rifle_offset.y - bullet_height_ / 2};
    instanciate_bullet_(std::make_unique<Bullet>(rifle_pos, vec2{bullet_speed * 2 + bullet_speed * charge_ * 2, 0}, bullet_texture_.get(), bullet_width_, bullet_height_));
    charge_ = 0;
}
