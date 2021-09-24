#include <player.hpp>
#include <cmath>
#include <iostream>
#include <constants.hpp>

inline const std::string player_texture_folder{texture_folder + "/player"};
inline const std::string player_move_spritesheet{player_texture_folder + "/move with FX.png"};
inline const std::string player_charge_spritesheet{player_texture_folder + "/charge.png"};
inline const std::string player_dash_spritesheet{player_texture_folder + "/GAS dash with FX.png"};
inline const std::string player_shoot_spritesheet{player_texture_folder + "/shoot with FX.png"};
inline const std::string player_Idle_spritesheet{player_texture_folder + "/static idle.png"};
inline const std::string player_death_spritesheet{player_texture_folder + "/death.png"};
inline const std::string player_wake_spritesheet{player_texture_folder + "/wake.png"};

Player::Player()
{
    LoadResource();
}

void Player::Update()
{
    switch (state_)
    {
    case PlayerState::Moving:
        Move();
        break;
    case PlayerState::Waking:
        Move();
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
    state_ = state;
    spritesheet_map_.at(state_).Reset();
    state_framecount = 0;
}

void Player::IncreaseFrameCount() 
{
    spritesheet_map_.at(state_).Tick();
}


void Player::OnKey(KeyEvent e)
{

    switch (state_)
    {
    case PlayerState::Moving:
        if (e.key_state == KeyState::pressed && (e.key == Key::Left || e.key == Key::Right))
        {
            SetDir(e.key);
        }
        else if (e.key_state == KeyState::released && ((e.key == Key::Left && dir_ == Dir::Left) || (e.key == Key::Right && dir_ == Dir::Right)))
        {
            SetState(PlayerState::Idle);
        }
        break;
    case PlayerState::Idle:
        if (e.key_state == KeyState::pressed && (e.key == Key::Left || e.key == Key::Right))
        {
            SetState(PlayerState::Waking);
            SetDir(e.key);
        }
        break;
    case PlayerState::Waking:
        if (GetSpritesheet().AnimationEnded())
        {
            if (e.key_state == KeyState::pressed && (e.key == Key::Left || e.key == Key::Right))
            {
                SetState(PlayerState::Moving);
                SetDir(e.key);
            }
        }
        else if (e.key_state == KeyState::released && ((e.key == Key::Left && dir_ == Dir::Left) || (e.key == Key::Right && dir_ == Dir::Right)))
        {
            SetState(PlayerState::Idle);
        }
        break;
    default:
        break;
    }
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
    dir_ = dir;
}

void Player::Move()
{
    int dir_mod = 1;
    if (dir_ == Dir::Left)
    {
        dir_mod = -1;
    }
    pos_.x += dir_mod * speed_;
}

uint32_t Player::GetStateFramecount() const
{
    return state_framecount;
}

void Player::LoadResource()
{

    spritesheet_map_.try_emplace(PlayerState::Moving, Spritesheet{std::make_shared<Texture>(player_move_spritesheet), 3, 8, 8});
    spritesheet_map_.try_emplace(PlayerState::Idle, Spritesheet{std::make_shared<Texture>(player_Idle_spritesheet), 3, 1, 1});
    spritesheet_map_.try_emplace(PlayerState::Dashing, Spritesheet{std::make_shared<Texture>(player_dash_spritesheet), 1});
    spritesheet_map_.try_emplace(PlayerState::Dying, Spritesheet{std::make_shared<Texture>(player_death_spritesheet), 6});
    spritesheet_map_.try_emplace(PlayerState::Shooting, Spritesheet{std::make_shared<Texture>(player_shoot_spritesheet), 6});
    spritesheet_map_.try_emplace(PlayerState::Charging, Spritesheet{std::make_shared<Texture>(player_charge_spritesheet), 4});
    spritesheet_map_.try_emplace(PlayerState::Waking, Spritesheet{std::make_shared<Texture>(player_wake_spritesheet), 3, 5, 5});
}

const Spritesheet &Player::GetSpritesheet() const
{
    return spritesheet_map_.at(state_);
}

vec2 Player::GetPos() const
{
    return pos_;
}

Dir Player::GetDir() const
{
    return dir_;
}
