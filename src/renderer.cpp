#include <renderer.hpp>
#include <constants.hpp>
#include <iostream>
#include <string>
#include <constants.hpp>
#include <texture.hpp>
#include <SDL2/SDL_ttf.h>

Renderer::Renderer()
    : screen_width(_screen_width),
      screen_height(_screen_height),
      grid_width(_grid_width),
      grid_height(_grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (nullptr == sdl_renderer)
  {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  TTF_Init();
  font = std::make_unique<Font>( (font_folder + "/pointfree.ttf").c_str(), 18 );
}

Renderer::~Renderer()
{
  font.reset();
  TTF_Quit();
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}
void Renderer::BeginRender()
{
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 175, 168, 147, 0xFF);
  SDL_RenderClear(sdl_renderer);
}

void Renderer::EndRender()
{

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

Renderer *Renderer::GetInstance()
{
  static Renderer instance;
  return &instance;
}

void Renderer::SetCamera(const Camera *camera)
{
  camera_ = camera;
}

void Renderer::Render(const std::vector<Bot> &bots)
{
  for (const Bot &bot : bots)
  {
    Render(&bot);
  }
}

void Renderer::Render(const std::vector<Prop> &props)
{
  for (const Prop &prop : props)
  {
    Render(&prop);
  }
}

void Renderer::Render(const IDrawable *drawable)
{
  drawable->Draw(sdl_renderer, camera_);
}

void Renderer::PrintText(SDL_Rect box, const char * text, SDL_Color color) 
{
  auto texture = font->TextToTexture(text, color);
  SDL_RenderCopy(sdl_renderer, texture->GetHandle(), NULL, &box);
}

void Renderer::Debug(int i)
{

}

void Renderer::DrawSky(Texture *sky_texture, Texture *sun_texture)
{
  SDL_Rect srcrect = sky_texture->GetRect();
  SDL_Rect dstrect;
  dstrect.w = _screen_width * 3;
  dstrect.x = floor(camera_->GetPos().x / 15 / dstrect.w) * (dstrect.w) - camera_->GetPos().x / 15;
  dstrect.y = 0 + camera_->GetPos().y / 10;
  dstrect.h = _background_level;
  SDL_RenderCopyEx(sdl_renderer, sky_texture->operator->(), &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
  dstrect.x += dstrect.w;
  SDL_RenderCopyEx(sdl_renderer, sky_texture->operator->(), &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
  srcrect = sun_texture->GetRect();
  dstrect.x = screen_width / 2 - camera_->GetPos().x / 50;
  dstrect.y = _background_level - _screen_height / 3;
  dstrect.w = _screen_height / 2;
  dstrect.h = _screen_height / 2;
  SDL_RenderCopyEx(sdl_renderer, sun_texture->operator->(), &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
}

void Renderer::DrawBackground(Texture *dunes_textures)
{
  SDL_Rect srcrect = dunes_textures->GetRect();
  SDL_Rect dstrect;
  dstrect.w = _screen_width *1.5;
  dstrect.x = floor(camera_->GetPos().x / 5 / dstrect.w) * (dstrect.w) - camera_->GetPos().x / 5;
  dstrect.y = _background_level - dunes_textures->GetHeight() * 1.5;
  dstrect.h = _screen_height / 4;
  SDL_RenderCopyEx(sdl_renderer, dunes_textures->operator->(), &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
  dstrect.x += dstrect.w;
  SDL_RenderCopyEx(sdl_renderer, dunes_textures->operator->(), &srcrect, &dstrect, 0, NULL, SDL_FLIP_NONE);
}

void Renderer::UpdateWindowTitle(int score_, int fps)
{
  std::string title{"Snake score_: " + std::to_string(score_) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

void Renderer::DrawFloor(Texture *ground_transition, Texture *dune_shadow)
{
  SDL_Rect srcrect = ground_transition->GetRect();
  SDL_Rect back_floor;
  back_floor.x = 0;
  back_floor.y = _background_level;
  back_floor.w = _screen_width;
  back_floor.h = _foreground_level - _background_level;
  SDL_RenderCopyEx(sdl_renderer, ground_transition->operator->(), &srcrect, &back_floor, 0, NULL, SDL_FLIP_NONE);

  SDL_Rect floor_rect;
  floor_rect.x = 0;
  floor_rect.y = _foreground_level;
  floor_rect.w = _screen_width;
  floor_rect.h = _screen_height - _foreground_level;
  SDL_SetRenderDrawColor(sdl_renderer, 0x9a, 0x5a, 0x4b, 0xFF);
  SDL_RenderFillRect(sdl_renderer, &floor_rect);

  //srcrect = dune_shadow->GetRect();
  //SDL_Rect shadow;
  //shadow.w = _screen_width;
  //shadow.x = floor(camera_->GetPos().x / 5 / shadow.w) * (shadow.w) - camera_->GetPos().x / 5;
  //shadow.y = _background_level;
  //shadow.h = _screen_width/10;
  //SDL_RenderCopyEx(sdl_renderer, dune_shadow->operator->(), &srcrect, &shadow, 0, NULL, SDL_FLIP_NONE);
  //shadow.x += shadow.w;
  //SDL_RenderCopyEx(sdl_renderer, dune_shadow->operator->(), &srcrect, &shadow, 0, NULL, SDL_FLIP_NONE);
}