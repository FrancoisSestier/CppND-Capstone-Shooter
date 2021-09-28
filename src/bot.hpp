#pragma once
#include "vec2.hpp"
#include "spritesheet.hpp"
#include "drawable.hpp"
#include "collidable.hpp"
#include "unordered_map"
#include "targetable.hpp"
#include "functional"
#include <bullet.hpp>

class SDL_Renderer;
class Camera;

enum class BotState
{
    Moving,
    Idle,
    Shooting,
    Hit,
    Dead,
    Charging
};

class Bot : public IDrawable, public ICollidable
{

public:
    using bullet_callback = std::function<void(vec2 pos, vec2 speed)>;

    Bot(vec2 pos, const std::unordered_map<BotState, std::shared_ptr<Texture>> &bot_texture, ITargetable *target, bullet_callback instanciate_bullet);
    void Update();
    vec2 GetPos() const;
    BotState GetState() const;
    bool IsAlive() const;
    const Spritesheet &GetSpritesheet() const;

    void Draw(SDL_Renderer *, const Camera *camera) const override;
    virtual void OnCollision(ICollidable *other) override;
    virtual AABB GetAABB() const override;
    virtual vec2 GetSpeed() const override;
    virtual collision_mask_t GetCollisionMask() const override;
private:
    bool TargetInRange();
    void Move();
    void ShootTarget();
    void SetState(BotState sate);
    std::unordered_map<BotState, Spritesheet> spritesheet_map_;
    BotState state_{BotState::Idle};
    vec2 pos_;
    vec2 speed_;
    ITargetable *target_;
    bullet_callback instanciate_bullet_;
    float width_{128};
    float height_{128};
    float max_speed{4.8};
    float max_shooting_range_{500};
    float shooting_force_{2.5f};
};
