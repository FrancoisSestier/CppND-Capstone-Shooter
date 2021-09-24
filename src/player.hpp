#pragma once
#include <vector>
#include "SDL.h"
#include <input.hpp>
#include <unordered_map>
#include <spritesheet.hpp>

enum class PlayerDirection{
    Right,
    Left
};

enum class PlayerState {
    Moving,
    Idle,
    Charging,
    Hit,
    Shooting,
    Dashing,
    Dying,
    Waking
};



class Player {
 public:

  Player() = default;

  void Update();

  PlayerState GetState() const { return state_ ;}

  void OnKeyDown(Key key);

 private:
  void LoadResource();

  PlayerDirection direction_{PlayerDirection::Right};
  PlayerState state_{PlayerState::Idle};

  SDL_Point pos_;
  float speed_{0.1f};
  bool alive_{true};
  std::unordered_map<PlayerState,Spritesheet> spritesheet_map_;
  uint32_t state_framecount{0};
};