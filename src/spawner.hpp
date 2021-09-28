#pragma once
#include <bullet.hpp>
#include <bot.hpp>
#include <targetable.hpp>

template <class Impl, typename T>
class Spawner
{
public:
    Spawner() = default;
    ~Spawner() = default;

    void spawn(vec2 pos, vec2 speed = vec2{0.0f,0.0f}) { return static_cast<Impl *>(this)->spawn_impl(pos, speed); }
};

class BotSpawner : public Spawner<BotSpawner, Bot>
{
    friend class Spawner<BotSpawner, Bot>;

public:
    BotSpawner(std::vector<Bot> *bots,ITargetable* target, Bot::bullet_callback instanciate_bullet) : bots_{bots}, instanciate_bullet_{instanciate_bullet}, target_{target}
    {
        auto charging_texture = std::make_shared<Texture>(bot_charging_texture);
        bot_textures_.emplace(BotState::Dead, std::make_shared<Texture>(bot_dead_texture));
        bot_textures_.emplace(BotState::Hit, std::make_shared<Texture>(bot_hit_texture));
        bot_textures_.emplace(BotState::Idle, charging_texture);
        bot_textures_.emplace(BotState::Moving, std::make_shared<Texture>(bot_walking_texture));
        bot_textures_.emplace(BotState::Shooting, std::make_shared<Texture>(bot_shooting_texture));
        bot_textures_.emplace(BotState::Charging, charging_texture);
    }

protected:
    void spawn_impl(vec2 pos, vec2 speed)
    {
        bots_->push_back(Bot{pos, bot_textures_,target_,instanciate_bullet_});
    }

    std::vector<Bot> *bots_;
    std::unordered_map<BotState, std::shared_ptr<Texture>> bot_textures_;
    ITargetable* target_;
    Bot::bullet_callback instanciate_bullet_;
    float width{40};
    float height{30};
};

class BotBulletSpawner : public Spawner<BotBulletSpawner, Bullet>
{
    friend class Spawner<BotBulletSpawner, Bullet>;

public:
    BotBulletSpawner(std::vector<std::unique_ptr<Bullet>> *bullets) : bullets_{bullets}, texture_{std::make_unique<Texture>(bot_bullet_texture_file)} {}

protected:
    void spawn_impl(vec2 pos, vec2 speed)
    {
        bullets_->push_back(std::make_unique<Bullet>(pos, speed, texture_.get(), width, height,CollisionLayer_Player));
    }

    std::vector<std::unique_ptr<Bullet>> *bullets_;
    std::unique_ptr<Texture> texture_;
    float width{20};
    float height{20};
};
