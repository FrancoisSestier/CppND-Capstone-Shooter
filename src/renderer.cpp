#include <renderer.hpp>
#include <constants.hpp>
#include <iostream>
#include <string>


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
}

Renderer::~Renderer()
{
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

Renderer* Renderer::GetInstance()
{
  static Renderer instance;
  return &instance;
}

void Renderer::Render(const Player &player)
{
}

void Renderer::UpdateWindowTitle(int score, int fps)
{
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
