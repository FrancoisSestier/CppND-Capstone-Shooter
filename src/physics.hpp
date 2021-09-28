#pragma once
#include <collidable.hpp>

namespace physics
{

    void CollisionCheck(ICollidable *lhs, ICollidable *rhs)
    {
        auto lhs_AABB = lhs->GetAABB();
        auto rhs_AABB = rhs->GetAABB();
        if (lhs_AABB.pos.x < rhs_AABB.pos.x + rhs_AABB.extent.x &&
            lhs_AABB.pos.x + lhs_AABB.extent.x > rhs_AABB.pos.x &&
            lhs_AABB.pos.y < rhs_AABB.pos.y + rhs_AABB.extent.y &&
            lhs_AABB.pos.y + lhs_AABB.extent.y > rhs_AABB.pos.y && (rhs->GetCollisionMask() & lhs->GetCollisionMask()))
        {
            lhs->OnCollision(rhs);
            rhs->OnCollision(lhs);
        }
    }

}