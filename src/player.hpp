#pragma once
#include <vector>
#include <SDL.h>
#include <input.hpp>
#include <unordered_map>
#include <spritesheet.hpp>
#include <event.hpp>
#include <vec2.hpp>
#include <constants.hpp>
#include <drawable.hpp>
#include <targetable.hpp>
#include <functional>
#include <bullet.hpp>
#include <collidable.hpp>

#pragma once

enum class Dir
{
    None,
    Right,
    Left
};

enum class PlayerState
{
    Moving,
    Idle,
    Charging,
    Hit,
    Shooting,
    Dashing,
    Dying,
    Waking,
    Dead
};

class Player : public IDrawable, public ITargetable, public ICollidable
{
    using bullet_callback = std::function<void(std::unique_ptr<Bullet>)>;

public:
    Player(bullet_callback instanciate_bullet);

    void Update();

    PlayerState GetState() const;
    void SetState(PlayerState state);
    void IncreaseFrameCount();
    void OnKey(KeyEvent e);
    void SetDir(Dir dir);
    void SetDir(Key key);
    void Move();
    void Reset();
    uint32_t GetStateFramecount() const;
    const Spritesheet &GetSpritesheet() const;
    const Spritesheet *GetMoveFX() const;
    bool Moving() const;
    vec2 GetPos() const;
    Dir GetFacingDir() const;
    Dir GetMoveDir() const;
    float GetWidth() const;
    float GetHeight() const;
    int GetScore() const;
    int GetHealth() const;
    bool IsAlive() const;
    void IncreaseScore(int to_add);

    //ICollidable
    virtual vec2 GetSpeed() const override;
    virtual AABB GetAABB() const override;
    virtual void OnCollision(ICollidable *other) override;
    collision_mask_t GetCollisionMask() const override;
    //IDrawable
    void Draw(SDL_Renderer *renderer, const Camera *camera) const override;
    //ITargetable
    Target GetTarget() const override;

private:
    void ProcessKeyEventMoving(KeyEvent e);
    void ProcessKeyEventShooting(KeyEvent e);
    void Shoot();
    void LoadResource();

    PlayerState state_{PlayerState::Idle};
    vec2 pos_{600, _foreground_level - 20};
    Dir facing_dir_{Dir::Right};
    vec2 speed_{0.f};
    float charge_{0.0f};
    float width_{170.f};
    float height_{108.f};
    float scale_{4.5f};
    float max_speed{4.f};
    float health_{100.f};
    int score_{0};

    bool alive_{true};
    bool moving_left_{false};
    bool moving_right_{false};
    bool moving_up_{false};
    bool moving_down_{false};

    uint8_t dead_frames_{0};
    const uint8_t max_dead_frames_{25};
    bool still_charging{false};
    std::unordered_map<PlayerState, Spritesheet> spritesheet_map_;
    std::unique_ptr<Spritesheet> move_fx_;
    std::unique_ptr<Texture> bullet_texture_;

    uint32_t state_framecount_{0};
    bullet_callback instanciate_bullet_;
};