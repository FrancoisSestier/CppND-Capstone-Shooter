#pragma once

#include <vector>
#include "SDL.h"
#include "player.hpp"

class Renderer
{

public:
  void Render(const Player &player);
  void BeginRender();
  void EndRender();
  void UpdateWindowTitle(int score, int fps);
  static Renderer* GetInstance();

  SDL_Renderer* GetHandle(){return sdl_renderer;}

protected:
  Renderer();
  ~Renderer();
  Renderer(const Renderer& other) = delete;
  Renderer(Renderer&& other) = delete;
  Renderer& operator=(const Renderer& other) = delete;
  Renderer& operator=(Renderer&& other) = delete;

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};
