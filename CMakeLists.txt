cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(game src/main.cpp src/event_dispatcher.cpp src/player.cpp src/game.cpp src/renderer.cpp src/texture.cpp src/spritesheet.cpp src/bot.cpp src/camera.cpp src/prop.cpp src/font.cpp src/prop_generator.cpp src/bullet.cpp src/thread_pool.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

target_link_libraries(game ${SDL2_LIBRARIES})
target_link_libraries(game SDL2_image)
target_link_libraries(game SDL2_ttf)
