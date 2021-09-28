#pragma once
#include <drawable.hpp>
#include <vec2.hpp>
#include <texture.hpp>
#include <collidable.hpp>

class SDL_Renderer;
class Camera;

class Bullet : public IDrawable, public ICollidable
{
public:
    Bullet(vec2 pos, vec2 speed, Texture *texture, float width = 160, float height = 50, collision_mask_t collision_mask = {CollisionLayer_Ennemy | CollisionLayer_Player});

    void Update();

    vec2 GetPos() const;
    float GetWidth() const;
    float GetHeight() const;
    bool IsActive() const;

    void Draw(SDL_Renderer *renderer, const Camera *camera) const override;

    virtual void OnCollision(ICollidable *other) override;
    virtual AABB GetAABB() const override;
    virtual vec2 GetSpeed() const override;
    virtual collision_mask_t GetCollisionMask() const override;

public:
    collision_mask_t collision_mask_;
    vec2 pos_;
    vec2 speed_;
    float width_{160};
    float height_{50};
    Texture *texture_;
    bool active_ = true;
};