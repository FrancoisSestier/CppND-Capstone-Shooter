#include <game.hpp>
#include <renderer.hpp>
#include <iostream>
#include <event_dispatcher.hpp>
#include "SDL.h"

Game::Game() {
  renderer_ = Renderer::GetInstance();
  event_dispatcher_.RegisterQuitCallback([this](){running_ = false;});
  event_dispatcher_.RegisterKeyEventCallback([this](KeyEvent e){player_.OnKey(e);});
}

void Game::Run() {

  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  running_ = true;

  while (running_) {
    
    Update();

    renderer_->BeginRender();
    renderer_->Render(player_);
    player_.IncreaseFrameCount();
    renderer_->EndRender();  

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    //if (frame_duration < target_frame_duration) {
    //  SDL_Delay(target_frame_duration - frame_duration);
    //}
    time.Update(SDL_GetTicks());
  }
}


void Game::Update() {
  event_dispatcher_.Dispatch();
  player_.Update();
}
