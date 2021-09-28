#include <game.hpp>
#include <renderer.hpp>
#include <iostream>
#include <constants.hpp>
#include <event_dispatcher.hpp>
#include "SDL.h"
#include "texture.hpp"
#include <vec2.hpp>
#include <bot.hpp>
#include <random>
#include <prop_generator.hpp>
#include <future>
#include <physics.hpp>

Game::Game() : player_{[this](std::unique_ptr<Bullet> bullet)
                       { InstanciateBullet(std::move(bullet)); }},
               camera_{&player_}
{
  renderer_ = Renderer::GetInstance();
  event_dispatcher_.RegisterQuitCallback([this]()
                                         { running_ = false; });
  event_dispatcher_.RegisterKeyEventCallback([this](KeyEvent e)
                                             {
                                               player_.OnKey(e);
                                               if (e.key == Key::R && e.key_state == KeyState::pressed)
                                               {
                                                 Restart();
                                               }
                                             });

  renderer_->SetCamera(&camera_);
  bot_bullet_spawner_ = std::make_unique<BotBulletSpawner>(&bullets_);
  bot_spawner_ = std::make_unique<BotSpawner>(&bots_, &player_, [this](vec2 pos, vec2 speed)
                                              { bot_bullet_spawner_->spawn(pos, speed); });
  LoadAssets();
  GenWorld(0, _screen_width);
}

void Game::Run()
{
  running_ = true;
  while (running_)
  {

    Update();

    Draw();

    time_.Update(SDL_GetTicks());
    if (time_.GetDeltaTime() < _target_frame_duration)
    {
      SDL_Delay(_target_frame_duration - time_.GetDeltaTime());
    }
  }
  if (extend_right_.valid())
  {
    extend_right_.wait();
  }
  if (extend_left_.valid())
  {
    extend_left_.wait();
  }
}

void Game::Restart()
{
  bullets_.clear();
  bots_.clear();
  player_.Reset();
}

void Game::InstanciateBullet(std::unique_ptr<Bullet> bullet)
{
  bullets_.push_back(std::move(bullet));
}

void Game::LoadAssets()
{
  background_resources_.sky_texture = std::make_unique<Texture>(sky_texture_file);
  background_resources_.sun_texture = std::make_unique<Texture>(sun_texture_file);
  background_resources_.dunes_texture = std::make_unique<Texture>(dunes_texture_file);
  background_resources_.dunes_shadow = std::make_unique<Texture>(dunes_shadow_texture_file);
  background_resources_.ground_transition_texture = std::make_unique<Texture>(ground_transition_texture_file);
  //dirt_textures_.push_back(std::make_unique<Texture>(barrel_texture_file));
  //dirt_textures_.push_back(std::make_unique<Texture>(blood_1_texture_file,true));
  //dirt_textures_.push_back(std::make_unique<Texture>(blood_2_texture_file,true));
  //dirt_textures_.push_back(std::make_unique<Texture>(box_texture_file));
  //dirt_textures_.push_back(std::make_unique<Texture>(crate_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_1_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_2_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_3_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_4_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_5_texture_file));
  prop_resources_.dirt_textures.push_back(std::make_unique<Texture>(dirt_6_texture_file));

  prop_resources_.grass_textures.push_back(std::make_unique<Texture>(grass_1_texture_file));
  prop_resources_.grass_textures.push_back(std::make_unique<Texture>(grass_2_texture_file));
  prop_resources_.grass_textures.push_back(std::make_unique<Texture>(grass_3_texture_file));
  prop_resources_.grass_textures.push_back(std::make_unique<Texture>(grass_4_texture_file));
  prop_resources_.grass_textures.push_back(std::make_unique<Texture>(grass_5_texture_file));

  //grave_textures_.push_back(std::make_unique<Texture>(building_1_texture_file));
  //grave_textures_.push_back(std::make_unique<Texture>(building_2_texture_file));
  //grave_textures_.push_back(std::make_unique<Texture>(building_3_texture_file));
  //prop_resources.building_textures.push_back(std::make_unique<Texture>(water_tower_texture_file));
  //grave_textures_.push_back(std::make_unique<Texture>(building_5_texture_file));
  //grave_textures_.push_back(std::make_unique<Texture>(building_6_texture_file));
  //
  prop_resources_.grave_textures.push_back(std::make_unique<Texture>(grave_1_texture_file));
  prop_resources_.grave_textures.push_back(std::make_unique<Texture>(grave_2_texture_file));
  //dirt_textures_.push_back(std::make_unique<Texture>(fence_1_texture_file));
  //dirt_textures_.push_back(std::make_unique<Texture>(fence_2_texture_file));
  //dirt_textures_.push_back(std::make_unique<Texture>(fence_3_texture_file));
}

void Game::Update()
{
  event_dispatcher_.Dispatch();
  player_.Update();
  for (auto &&bot = bots_.begin(); bot != bots_.end();)
  {
    bot->Update();
    if (!bot->IsAlive())
    {
      bot = bots_.erase(bot);
      player_.IncreaseScore(1);
      continue;
    }
    bot++;
  }
  for (auto &&bullet = bullets_.begin(); bullet != bullets_.end();)
  {
    (*bullet)->Update();
    if (!(*bullet)->IsActive() || (*bullet)->GetPos().x + (*bullet)->GetWidth() < camera_.GetPos().x || (*bullet)->GetPos().x > (camera_.GetPos().x + _screen_width))
    {
      bullet = bullets_.erase(bullet);
      continue;
    }
    bullet++;
  }

  camera_.Update();
  CollisionCheck();
  AutoWorldGen();
  AutoSpwanBots();
}

void Game::GenWorld(float x_start, float width)
{
  if (x_start < left_world_gen_extent)
  {
    left_world_gen_extent = x_start;
  }
  if (x_start + width > right_world_gen_extent)
  {
    right_world_gen_extent = x_start + width;
  }

  prop_generator::prop_generation_settings grass_settings{x_start, x_start + width};
  grass_settings.proc_prob = .01;
  grass_settings.proc_mod = 60;
  prop_generator::prop_generation_settings dirt_settings{x_start, x_start + width};
  dirt_settings.proc_prob = .1;
  dirt_settings.start_pos.y = _screen_height - 325;
  dirt_settings.max_offset.y = 50;
  std::lock_guard<std::mutex> lk(prop_mutex_);
  for (size_t i = 0; i < 50; i++)
  {
    prop_generator::procedural_prop_gen(prop_resources_.dirt_textures, dirt_settings, background_props_);
  }

  grass_settings.start_pos.y = _screen_height - 200;
  prop_generator::procedural_prop_gen(prop_resources_.grass_textures, grass_settings, background_props_);
}

void Game::Draw()
{

  renderer_->BeginRender();
  renderer_->DrawSky(background_resources_.sky_texture.get(), background_resources_.sun_texture.get());
  renderer_->DrawBackground(background_resources_.dunes_texture.get());

  renderer_->DrawFloor(background_resources_.ground_transition_texture.get(), background_resources_.dunes_shadow.get());
  {
    std::lock_guard<std::mutex> lk(prop_mutex_);
    for (auto &&prop : background_props_)
    {
      renderer_->Render(&prop);
    }
  }

  renderer_->Render(bots_);
  renderer_->Render(&player_);
  for (auto &&bullet : bullets_)
  {
    renderer_->Render(bullet.get());
  }
#ifndef NDEBUG
  renderer_->PrintText(SDL_Rect{0, 80, 150, 40}, ("FPS :" + std::to_string(time_.GetFPS())).c_str(), SDL_Color{255, 255, 255});
#endif
  renderer_->PrintText(SDL_Rect{0, 40, 150, 40}, ("Score :" + std::to_string(player_.GetScore())).c_str(), SDL_Color{255, 255, 255});
  renderer_->PrintText(SDL_Rect{0, 0, 150, 40}, ("Health :" + std::to_string(player_.GetHealth())).c_str(), SDL_Color{255, 255, 255});
  if (!player_.IsAlive())
  {
    renderer_->PrintText(SDL_Rect{_screen_width / 2 - 300, _screen_height / 2 - 100, 600, 200}, "Press R to restart", SDL_Color{255, 255, 255});
  }
  player_.IncreaseFrameCount();
  renderer_->EndRender();
}

void Game::AutoWorldGen()
{
  if (camera_.GetPos().x < left_world_gen_extent)
  {
    if (extend_left_.valid())
    {
      extend_left_.wait();
    }
    auto extend_left_ = thread_pool_.push(&Game::GenWorld, this, floor(camera_.GetPos().x / _screen_width) * (_screen_width), (float)_screen_width);
  }
  if (camera_.GetPos().x + _screen_width > right_world_gen_extent)
  {
    if (extend_right_.valid())
    {
      extend_right_.wait();
    }
    auto extend_right_ = thread_pool_.push(&Game::GenWorld, this, floor((camera_.GetPos().x + _screen_width) / _screen_width) * (_screen_width), (float)_screen_width);
  }
}

void Game::CollisionCheck()
{
  for (auto &&bulletA : bullets_)
  {
    for (auto &&bulletB : bullets_)
    {
      if (bulletA != bulletB)
      {
        physics::CollisionCheck(bulletA.get(), bulletB.get());
      }
    }
    for (auto &&bot : bots_)
    {
      physics::CollisionCheck(bulletA.get(), &bot);
    }
    physics::CollisionCheck(bulletA.get(), &player_);
  }
}

void Game::AutoSpwanBots()
{
  std::mt19937 gen(rd_()); //Standard mersenne_twister_engine seeded with rd()

  std::uniform_int_distribution<int> coin(0, 1);
  std::uniform_real_distribution<float> rand_x(800, 1200);
  std::uniform_real_distribution<float> rand_y(_foreground_level + 20, _screen_height - 20);
  vec2 pos;
  do
  {
    pos = vec2{coin(gen) != 0 ? -rand_x(gen) + player_.GetPos().x : rand_x(gen) + player_.GetPos().x, rand_y(gen)};
  } while (pos.x > camera_.GetPos().x && pos.x < camera_.GetPos().x + _screen_width);
  if (bots_.size() < player_.GetScore() + 1)
  {
    bot_spawner_->spawn(pos);
  }
}
