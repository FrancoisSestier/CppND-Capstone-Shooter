#pragma once
#include <memory>
#include <texture.hpp>

struct BackgroundResources
{
  std::unique_ptr<Texture> sky_texture;
  std::unique_ptr<Texture> ground_transition_texture;
  std::unique_ptr<Texture> sun_texture;
  std::unique_ptr<Texture> dunes_shadow;
  std::unique_ptr<Texture> dunes_texture;
};

struct PropResources
{
  std::vector<std::unique_ptr<Texture>> dirt_textures;
  std::vector<std::unique_ptr<Texture>> grass_textures;
  std::vector<std::unique_ptr<Texture>> grave_textures;
  std::vector<std::unique_ptr<Texture>> building_textures;
};