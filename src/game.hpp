#pragma once
#include <random>
#include <SDL.h>
#include <event_dispatcher.hpp>
#include <renderer.hpp>
#include <player.hpp>
#include <time.hpp>

class Game
{
public:

  Game();

  void Run();

  int GetSize() const;

private:
  void Update();
  Renderer* renderer_;
  int score{0};
  EventDispatcher event_dispatcher_;
  Time time;
  Player player_;
  bool running_ = false;
};
