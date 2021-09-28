#pragma once
#include <random>
#include <SDL.h>
#include <event_dispatcher.hpp>
#include <renderer.hpp>
#include <player.hpp>
#include <time.hpp>
#include <memory>
#include <spritesheet.hpp>
#include <vector>
#include <bot.hpp>
#include <prop.hpp>
#include <bullet.hpp>
#include <mutex>
#include <spawner.hpp>
#include <resources.hpp>
#include <future>
#include <thread_pool.hpp>

class Game
{
public:
  Game();

  void Run();
  void Restart();

  int GetSize() const;
  void InstanciateBullet(std::unique_ptr<Bullet> bullet);

private:
  void LoadAssets();
  void Update();
  void GenWorld(float x_start, float width);
  void Draw();
  void AutoWorldGen();
  void CollisionCheck();
  void AutoSpwanBots();
  
  Renderer *renderer_;
  ThreadPool thread_pool_;

  EventDispatcher event_dispatcher_;

  BackgroundResources background_resources_;
  PropResources prop_resources_;

  Player player_;
  Camera camera_;
  std::vector<Prop> background_props_;
  std::vector<Bot> bots_;
  std::vector<std::unique_ptr<Bullet>> bullets_;
  std::future<void> extend_left_;
  std::future<void> extend_right_;
  

  Time time_;

  bool running_ = false;

  float left_world_gen_extent{0};
  float right_world_gen_extent{0};

  std::unique_ptr<BotBulletSpawner> bot_bullet_spawner_;
  std::unique_ptr<BotSpawner> bot_spawner_;
  std::random_device rd_;

  mutable std::mutex prop_mutex_;
};
