#pragma once
#include <texture.hpp>
#include <constants.hpp>
#include <memory>
#include <prop.hpp>
#include <vec2.hpp>
#include <vector>

namespace prop_generator
{
    struct prop_generation_settings
    {
        prop_generation_settings(float start, float width) {start_pos.x = start; end_pos.x = width;}

        vec2 start_pos{0, _foreground_level + 10};
        vec2 min_offset{1, 1};
        vec2 max_offset{20, 100};
        vec2 end_pos{_screen_width * 10, 0};
        bool flipable = true;
        float max_rotation_offset = 0;
        float min_rotation_offset = 0;
        float proc_prob = .2;
        float proc_mod = 1;
        float non_proc_mod = 1;
        float min_scale = 4.5;
        float max_scale = 4.8;

    };

    void procedural_prop_gen(const std::vector<std::unique_ptr<Texture>> &texture_pool, const prop_generation_settings &settings, std::vector<Prop> &out);

    void procedural_prop_multi_layer_gen(const std::vector<std::unique_ptr<Texture>> &texture_pool, const prop_generation_settings &settings, std::vector<Prop> &out,int layer_count = 4);


} // namespace prop_generator
