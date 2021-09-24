#include <event_dispatcher.hpp>
#include <iostream>
#include <SDL.h>
#include <functional>
#include <input.hpp>

void EventDispatcher::Dispatch() const
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_QUIT)
    {
      if (quit_callback_)
      {
        quit_callback_();
      }
    }
    else if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        DispatchKeyDown(Key::Up);
        break;

      case SDLK_DOWN:
        DispatchKeyDown(Key::Down);
        break;

      case SDLK_LEFT:
        DispatchKeyDown(Key::Left);
        break;

      case SDLK_RIGHT:
        DispatchKeyDown(Key::Right);
        break;
      case SDLK_w:
        DispatchKeyDown(Key::Up);
        break;
      case SDLK_a:
        DispatchKeyDown(Key::Left);
        break;
      case SDLK_s:
        DispatchKeyDown(Key::Down);
        break;
      case SDLK_d:
        DispatchKeyDown(Key::Right);
        break;
      case SDLK_e:
        DispatchKeyDown(Key::Right);
        break;
      case SDLK_LSHIFT:
        DispatchKeyDown(Key::Shift);
        break;
      }
    }
  }
}

void EventDispatcher::DispatchKeyDown(Key key) const
{
  for (auto &callbacks : key_down_callbacks_)
  {
    callbacks(key);
  }
}

void EventDispatcher::RegisterKeyDownCallback(std::function<void(Key)> callback)
{
  key_down_callbacks_.push_back(callback);
}

void EventDispatcher::RegisterQuitCallback(std::function<void()> callback)
{
  quit_callback_ = callback;
}