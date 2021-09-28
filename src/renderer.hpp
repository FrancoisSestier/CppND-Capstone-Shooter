#pragma once

#include <vector>
#include "SDL.h"
#include "player.hpp"
#include "bot.hpp"
#include "camera.hpp"
#include <prop.hpp>
#include <font.hpp>

class Renderer
{

public:

  void Render(const std::vector<Bot> &bots);
  void Render(const std::vector<Prop> &props);
  void PrintText(SDL_Rect pos, const char * text, SDL_Color color);

  void Render(const IDrawable* drawable);

  void Debug(int i);

  void DrawSky(Texture *sky_texture, Texture *sun_texture);
  void DrawBackground(Texture *dunes_textures);

  void BeginRender();
  void EndRender();
  void DrawFloor(Texture* ground_transition, Texture* dune_shadow);
  void UpdateWindowTitle(int score_, int fps);
  static Renderer *GetInstance();

  void SetCamera(const Camera *camera);

  SDL_Renderer *GetHandle() { return sdl_renderer; }

protected:
  Renderer();
  ~Renderer();
  Renderer(const Renderer &other) = delete;
  Renderer(Renderer &&other) = delete;
  Renderer &operator=(const Renderer &other) = delete;
  Renderer &operator=(Renderer &&other) = delete;

private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  std::unique_ptr<Font> font = nullptr;
  const Camera *camera_;
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};
