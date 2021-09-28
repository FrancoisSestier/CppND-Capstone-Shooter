
#include <prop_generator.hpp>
#include <random>

namespace prop_generator
{
    std::random_device rd_;
    std::mt19937 gen(rd_()); //Standard mersenne_twister_engine seeded with rd()

    void procedural_prop_gen(const std::vector<std::unique_ptr<Texture>> &texture_pool, const prop_generation_settings &settings, std::vector<Prop> &out)
    {
        vec2 current_pos{settings.start_pos};
        std::uniform_real_distribution<float> x_offset_generator(settings.min_offset.x, settings.max_offset.x);
        std::uniform_real_distribution<float> y_offset_generator(settings.min_offset.y, settings.max_offset.y);
        std::uniform_real_distribution<float> rand_rotation(settings.min_rotation_offset, settings.max_rotation_offset);
        std::uniform_real_distribution<float> rand_scale(settings.min_scale, settings.max_scale);

        std::uniform_int_distribution<> rand_prop(0, texture_pool.size() - 1);
        std::uniform_real_distribution<float> proc(0.f, 1.f);
        std::uniform_int_distribution<short> coin_flip(0, 1);

        std::vector<Prop> props;

        float x_offset = x_offset_generator(gen);
        current_pos.x += x_offset;
        float proc_mod = settings.proc_mod;
        while (current_pos.x <= settings.end_pos.x)
        {
            if (proc(gen)  < settings.proc_prob* proc_mod)
            {
                current_pos.y = settings.start_pos.y + y_offset_generator(gen);
                Texture *texture = texture_pool.at(rand_prop(gen)).get();
                float scale = rand_scale(gen);
                out.push_back(Prop{vec2{current_pos.x, current_pos.y}, texture, settings.flipable ? static_cast<bool>(coin_flip(gen)) : false,scale, rand_rotation(gen)});

                do
                {
                    x_offset = settings.max_offset.x > texture->GetWidth() * scale ? x_offset_generator(gen) : texture->GetWidth() * scale + 1;

                } while (x_offset < texture->GetWidth() * scale);
                proc_mod = settings.proc_mod;            }
            else
            {
                proc_mod = settings.non_proc_mod;
                x_offset = x_offset_generator(gen);
            }
            current_pos.x += x_offset;
        }
    }

    void procedural_prop_multi_layer_gen(const std::vector<std::unique_ptr<Texture>> &texture_pool, const prop_generation_settings &settings, std::vector<Prop> &out, int layer_count)
    {
        float layer_spacing = (_screen_width - _foreground_level) / layer_count;
        prop_generation_settings current_settings = settings;
        for (size_t i = 0; i < layer_count; i++)
        {
            procedural_prop_gen(texture_pool, current_settings, out);
            current_settings.start_pos.y += layer_spacing;
        }
    }
}