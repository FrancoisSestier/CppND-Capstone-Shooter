#pragma once
#include <cstddef>
#include <string>

//inline constexpr std::size_t kFramesPerSecond{120};
//inline constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
inline constexpr std::size_t _screen_height{1080};
inline constexpr std::size_t _screen_width{1440};
inline constexpr std::size_t _grid_width{64};
inline constexpr std::size_t _grid_height{64};
inline constexpr std::size_t _background_level{550};
inline constexpr std::size_t _foreground_level{730};
inline constexpr std::size_t _target_frame_duration{16};
inline constexpr float PI{3.14159265358979323846};
inline const std::string asset_folder{"../assets"};
inline const std::string texture_folder{asset_folder + "/texture"};

inline const std::string bullets_folder{texture_folder + "/bullets"};

inline const std::string bot_bullet_texture_file{bullets_folder + "/bullet2.png"};

inline const std::string bot_folder{texture_folder + "/bot"};
inline const std::string bot_charging_texture{bot_folder + "/bot charging.png"};
inline const std::string bot_hit_texture{bot_folder + "/hit_bot_2.png"};
inline const std::string bot_walking_texture{bot_folder + "/bot_walk.png"};
inline const std::string bot_dead_texture{bot_folder + "/dead_bot.png"};
inline const std::string bot_shooting_texture{bot_folder + "/shooting_bot.png"};

inline const std::string prop_folder{texture_folder + "/props"};
inline const std::string sky_texture_file{prop_folder + "/sky.png"};
inline const std::string sun_texture_file{prop_folder + "/sun.png"};
inline const std::string dunes_texture_file{prop_folder + "/dunes.png"};
inline const std::string dunes_shadow_texture_file{prop_folder + "/dunes_shadow.png"};

inline const std::string barrel_texture_file{prop_folder + "/barrel.png"};
inline const std::string blood_1_texture_file{prop_folder + "/blood_1.png"};
inline const std::string blood_2_texture_file{prop_folder + "/blood_2.png"};
inline const std::string box_texture_file{prop_folder + "/box.png"};
inline const std::string crate_texture_file{prop_folder + "/crate.png"};
inline const std::string dirt_1_texture_file{prop_folder + "/dirt_1.png"};
inline const std::string dirt_2_texture_file{prop_folder + "/dirt_2.png"};
inline const std::string dirt_3_texture_file{prop_folder + "/dirt_3.png"};
inline const std::string dirt_4_texture_file{prop_folder + "/dirt_4.png"};
inline const std::string dirt_5_texture_file{prop_folder + "/dirt_5.png"};
inline const std::string dirt_6_texture_file{prop_folder + "/dirt_6.png"};

inline const std::string grass_1_texture_file{prop_folder + "/grass_1.png"};
inline const std::string grass_2_texture_file{prop_folder + "/grass_2.png"};
inline const std::string grass_3_texture_file{prop_folder + "/grass_3.png"};
inline const std::string grass_4_texture_file{prop_folder + "/grass_4.png"};

inline const std::string grass_5_texture_file{prop_folder + "/grass_5.png"};
inline const std::string grave_1_texture_file{prop_folder + "/grave_1.png"};
inline const std::string grave_2_texture_file{prop_folder + "/grave_2.png"};

inline const std::string fence_1_texture_file{prop_folder + "/fence_1.png"};
inline const std::string fence_2_texture_file{prop_folder + "/fence_2.png"};
inline const std::string fence_3_texture_file{prop_folder + "/fence_3.png"};

inline const std::string building_1_texture_file{prop_folder + "/building_1.png"};
inline const std::string building_2_texture_file{prop_folder + "/building_2.png"};
inline const std::string building_3_texture_file{prop_folder + "/building_3.png"};
inline const std::string building_4_texture_file{prop_folder + "/building_4.png"};
inline const std::string building_5_texture_file{prop_folder + "/building_5.png"};
inline const std::string building_6_texture_file{prop_folder + "/building_6.png"};
inline const std::string water_tower_texture_file{prop_folder + "/water_tower.png"};

inline const std::string ground_transition_texture_file{prop_folder + "/ground_transition.png"};

inline const std::string font_folder{asset_folder + "/fonts"};
