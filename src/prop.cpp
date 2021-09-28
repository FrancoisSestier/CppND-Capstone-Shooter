#include <prop.hpp>
#include <constants.hpp>
#include <math.h>
void Prop::SetPos(vec2 pos)
{
    pos_ = pos;
}

vec2 Prop::GetPos() const
{
    return pos_;
}

Texture *Prop::GetTexture() const
{
    return texture_;
}

bool Prop::GetFlip() const
{
    return flip_;
}

void Prop::Draw(SDL_Renderer *renderer, const Camera *camera) const
{
    SDL_Rect srcrect = texture_->GetRect();
    SDL_Rect dstrect = srcrect;
    dstrect.x = pos_.x - camera->GetPos().x/parallax_mod_;///(((_screen_height - pos_.y)/_ground_level)/+1);
    dstrect.y =  pos_.y + camera->GetPos().y;
    dstrect.w *= scale_;
    dstrect.h *= scale_;
    SDL_RendererFlip flip = flip_ ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;

    SDL_RenderCopyEx(renderer, texture_->operator->(), &srcrect, &dstrect, rotation_, NULL, flip);
}


Prop::Prop(vec2 pos, Texture *texture, bool flip, float scale, float rotation) : pos_{pos}, texture_{texture}, flip_{flip}, scale_{scale}, rotation_{rotation}
{
    parallax_mod_ = (pos_.y + texture_->GetHeight() * scale_ > _foreground_level) ? 1 : 1; 
}
