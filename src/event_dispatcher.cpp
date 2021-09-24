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
    else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
    {
      KeyState key_state = (e.type == SDL_KEYDOWN ? KeyState::pressed : KeyState::released);

      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        DispatchKeyEvent(KeyEvent{Key::Up,key_state});
        break;
      case SDLK_DOWN:
        DispatchKeyEvent(KeyEvent{Key::Down,key_state});
        break;
      case SDLK_LEFT:
        DispatchKeyEvent(KeyEvent{Key::Left,key_state});
        break;
      case SDLK_RIGHT:
        DispatchKeyEvent(KeyEvent{Key::Right,key_state});
        break;
      case SDLK_w:
        DispatchKeyEvent(KeyEvent{Key::Up,key_state});
        break;
      case SDLK_a:
        DispatchKeyEvent(KeyEvent{Key::Left,key_state});
        break;
      case SDLK_s:
        DispatchKeyEvent(KeyEvent{Key::Down,key_state});
        break;
      case SDLK_d:
        DispatchKeyEvent(KeyEvent{Key::Right,key_state});
        break;
      case SDLK_e:
        DispatchKeyEvent(KeyEvent{Key::Shoot,key_state});
        break;
      case SDLK_LSHIFT:
        DispatchKeyEvent(KeyEvent{Key::Dash,key_state});
        break;
      }
    }
  }
}

void EventDispatcher::DispatchKeyEvent(KeyEvent e) const
{
  for (auto &callbacks : key_event_callbacks_)
  {
    callbacks(e);
  }
}

void EventDispatcher::RegisterKeyEventCallback(std::function<void(KeyEvent)> callback)
{
  key_event_callbacks_.push_back(callback);
}

void EventDispatcher::RegisterQuitCallback(std::function<void()> callback)
{
  quit_callback_ = callback;
}