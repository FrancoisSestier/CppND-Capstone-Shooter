#pragma once
#include <vector>
#include <SDL.h>
#include <input.hpp>
#include <unordered_map>
#include <spritesheet.hpp>
#include <event.hpp>
#include <vec2.hpp>

enum class Dir
{
    Right,
    Left
};

enum class PlayerState
{
    Moving,
    Idle,
    Charging,
    Hit,
    Shooting,
    Dashing,
    Dying,
    Waking
};

class Player
{
public:
    Player();

    void Update();

    PlayerState GetState() const;
    void SetState(PlayerState state);
    void IncreaseFrameCount();
    void OnKey(KeyEvent e);
    void SetDir(Dir dir);
    void SetDir(Key key);
    void Move();
    uint32_t GetStateFramecount() const;
    const Spritesheet& GetSpritesheet() const;
    vec2 GetPos() const;
    Dir GetDir() const;

private:
    void LoadResource();

    PlayerState state_{PlayerState::Idle};
    vec2 pos_{50,200};
    Dir dir_{Dir::Right};
    float speed_{.3f};
    float charge_{0.0f};
    bool alive_{true};
    bool still_charging{false};
    std::unordered_map<PlayerState, Spritesheet> spritesheet_map_;
    uint32_t state_framecount{0};
};