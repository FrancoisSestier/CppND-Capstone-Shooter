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

void Player::Update()
{
}

void Player::OnKeyDown(Key key)
{
    switch (state_)
    {
    case PlayerState::Moving:
        switch (key)
        {
        case Key::Left:
        case Key::Right:
            //Move(Dir(key))
            break;
        default:
            state_ = PlayerState::Idle;
            break;
        }
        break;
    case PlayerState::Waking:
        switch (key)
        {
        case Key::Left:
        case Key::Right:
            if (state_framecount > spritesheet_map_[PlayerState::Waking].GetFrameCount())
            {
                state_ = PlayerState::Moving;
                //Move
            }
            break;
        default:
            state_ = PlayerState::Idle;
            break;
        }
        break;

    default:
        break;
    }
    switch (key)
    {
    case Key::Left:
    case Key::Right:
        switch (state_)
        {
        case PlayerState::Moving:
            //Move(Dir(key))
            break;
        case PlayerState::Idle:
            state_ = PlayerState::Waking;
            break;
        case PlayerState::Waking:
            if (state_framecount > spritesheet_map_[PlayerState::Waking].GetFrameCount())
            {
                state_ = PlayerState::Moving;
                //Move
            }
            break;
        default:
            break;
        }
        break;
    case Key::Shoot:
        switch (state_)
        {
        case break;

            default:
            break;
        }

    default:
        break;
    }
}

void Player::LoadResource()
{

    spritesheet_map_.emplace(PlayerState::Moving, Spritesheet{std::make_shared<Texture>(player_move_spritesheet), 8});
    spritesheet_map_.emplace(PlayerState::Idle, Spritesheet{std::make_shared<Texture>(player_Idle_spritesheet), 1});
    spritesheet_map_.emplace(PlayerState::Dashing, Spritesheet{std::make_shared<Texture>(player_dash_spritesheet), 1});
    spritesheet_map_.emplace(PlayerState::Dying, Spritesheet{std::make_shared<Texture>(player_death_spritesheet), 6});
    spritesheet_map_.emplace(PlayerState::Shooting, Spritesheet{std::make_shared<Texture>(player_shoot_spritesheet), 6});
    spritesheet_map_.emplace(PlayerState::Charging, Spritesheet{std::make_shared<Texture>(player_charge_spritesheet), 6});
    spritesheet_map_.emplace(PlayerState::Waking, Spritesheet{std::make_shared<Texture>(player_charge_spritesheet), 6});
}