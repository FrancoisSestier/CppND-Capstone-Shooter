#pragma once
#include <vec2.hpp>

struct AABB
{
    vec2 pos;
    vec2 extent;
};

static constexpr uint8_t CollisionLayer_Ennemy =  0b0001 ;
static constexpr uint8_t CollisionLayer_Player =  0b0010 ;
static constexpr uint8_t CollisionLayer_Bullet =  0b0100 ;

using collision_mask_t = uint8_t;

class ICollidable
{
public:
    virtual ~ICollidable() = default;

    virtual void OnCollision(ICollidable *other) = 0;
    virtual AABB GetAABB() const = 0;
    virtual vec2 GetSpeed() const = 0;
    virtual uint8_t GetCollisionMask() const = 0;
};