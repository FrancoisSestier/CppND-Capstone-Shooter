# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/francois/Dev/CppND-Capstone-Shooter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/francois/Dev/CppND-Capstone-Shooter/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/main.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

CMakeFiles/game.dir/src/event_dispatcher.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/event_dispatcher.cpp.o: ../src/event_dispatcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/event_dispatcher.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/event_dispatcher.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/event_dispatcher.cpp

CMakeFiles/game.dir/src/event_dispatcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/event_dispatcher.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/event_dispatcher.cpp > CMakeFiles/game.dir/src/event_dispatcher.cpp.i

CMakeFiles/game.dir/src/event_dispatcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/event_dispatcher.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/event_dispatcher.cpp -o CMakeFiles/game.dir/src/event_dispatcher.cpp.s

CMakeFiles/game.dir/src/player.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/player.cpp.o: ../src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/player.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/player.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/player.cpp

CMakeFiles/game.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/player.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/player.cpp > CMakeFiles/game.dir/src/player.cpp.i

CMakeFiles/game.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/player.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/player.cpp -o CMakeFiles/game.dir/src/player.cpp.s

CMakeFiles/game.dir/src/game.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/game.cpp.o: ../src/game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/game.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/game.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/game.cpp

CMakeFiles/game.dir/src/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/game.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/game.cpp > CMakeFiles/game.dir/src/game.cpp.i

CMakeFiles/game.dir/src/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/game.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/game.cpp -o CMakeFiles/game.dir/src/game.cpp.s

CMakeFiles/game.dir/src/renderer.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/renderer.cpp.o: ../src/renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/renderer.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/renderer.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/renderer.cpp

CMakeFiles/game.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/renderer.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/renderer.cpp > CMakeFiles/game.dir/src/renderer.cpp.i

CMakeFiles/game.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/renderer.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/renderer.cpp -o CMakeFiles/game.dir/src/renderer.cpp.s

CMakeFiles/game.dir/src/texture.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/texture.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/texture.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/texture.cpp

CMakeFiles/game.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/texture.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/texture.cpp > CMakeFiles/game.dir/src/texture.cpp.i

CMakeFiles/game.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/texture.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/texture.cpp -o CMakeFiles/game.dir/src/texture.cpp.s

CMakeFiles/game.dir/src/spritesheet.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/spritesheet.cpp.o: ../src/spritesheet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/src/spritesheet.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/spritesheet.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/spritesheet.cpp

CMakeFiles/game.dir/src/spritesheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/spritesheet.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/spritesheet.cpp > CMakeFiles/game.dir/src/spritesheet.cpp.i

CMakeFiles/game.dir/src/spritesheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/spritesheet.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/spritesheet.cpp -o CMakeFiles/game.dir/src/spritesheet.cpp.s

CMakeFiles/game.dir/src/bot.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/bot.cpp.o: ../src/bot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/src/bot.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/bot.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/bot.cpp

CMakeFiles/game.dir/src/bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/bot.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/bot.cpp > CMakeFiles/game.dir/src/bot.cpp.i

CMakeFiles/game.dir/src/bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/bot.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/bot.cpp -o CMakeFiles/game.dir/src/bot.cpp.s

CMakeFiles/game.dir/src/camera.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/game.dir/src/camera.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/camera.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/camera.cpp

CMakeFiles/game.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/camera.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/camera.cpp > CMakeFiles/game.dir/src/camera.cpp.i

CMakeFiles/game.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/camera.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/camera.cpp -o CMakeFiles/game.dir/src/camera.cpp.s

CMakeFiles/game.dir/src/prop.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/prop.cpp.o: ../src/prop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/game.dir/src/prop.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/prop.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/prop.cpp

CMakeFiles/game.dir/src/prop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/prop.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/prop.cpp > CMakeFiles/game.dir/src/prop.cpp.i

CMakeFiles/game.dir/src/prop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/prop.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/prop.cpp -o CMakeFiles/game.dir/src/prop.cpp.s

CMakeFiles/game.dir/src/font.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/font.cpp.o: ../src/font.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/game.dir/src/font.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/font.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/font.cpp

CMakeFiles/game.dir/src/font.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/font.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/font.cpp > CMakeFiles/game.dir/src/font.cpp.i

CMakeFiles/game.dir/src/font.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/font.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/font.cpp -o CMakeFiles/game.dir/src/font.cpp.s

CMakeFiles/game.dir/src/prop_generator.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/prop_generator.cpp.o: ../src/prop_generator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/game.dir/src/prop_generator.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/prop_generator.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/prop_generator.cpp

CMakeFiles/game.dir/src/prop_generator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/prop_generator.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/prop_generator.cpp > CMakeFiles/game.dir/src/prop_generator.cpp.i

CMakeFiles/game.dir/src/prop_generator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/prop_generator.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/prop_generator.cpp -o CMakeFiles/game.dir/src/prop_generator.cpp.s

CMakeFiles/game.dir/src/bullet.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/bullet.cpp.o: ../src/bullet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/game.dir/src/bullet.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/src/bullet.cpp.o -c /home/francois/Dev/CppND-Capstone-Shooter/src/bullet.cpp

CMakeFiles/game.dir/src/bullet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/src/bullet.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/francois/Dev/CppND-Capstone-Shooter/src/bullet.cpp > CMakeFiles/game.dir/src/bullet.cpp.i

CMakeFiles/game.dir/src/bullet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/bullet.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/francois/Dev/CppND-Capstone-Shooter/src/bullet.cpp -o CMakeFiles/game.dir/src/bullet.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/main.cpp.o" \
"CMakeFiles/game.dir/src/event_dispatcher.cpp.o" \
"CMakeFiles/game.dir/src/player.cpp.o" \
"CMakeFiles/game.dir/src/game.cpp.o" \
"CMakeFiles/game.dir/src/renderer.cpp.o" \
"CMakeFiles/game.dir/src/texture.cpp.o" \
"CMakeFiles/game.dir/src/spritesheet.cpp.o" \
"CMakeFiles/game.dir/src/bot.cpp.o" \
"CMakeFiles/game.dir/src/camera.cpp.o" \
"CMakeFiles/game.dir/src/prop.cpp.o" \
"CMakeFiles/game.dir/src/font.cpp.o" \
"CMakeFiles/game.dir/src/prop_generator.cpp.o" \
"CMakeFiles/game.dir/src/bullet.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/src/event_dispatcher.cpp.o
game: CMakeFiles/game.dir/src/player.cpp.o
game: CMakeFiles/game.dir/src/game.cpp.o
game: CMakeFiles/game.dir/src/renderer.cpp.o
game: CMakeFiles/game.dir/src/texture.cpp.o
game: CMakeFiles/game.dir/src/spritesheet.cpp.o
game: CMakeFiles/game.dir/src/bot.cpp.o
game: CMakeFiles/game.dir/src/camera.cpp.o
game: CMakeFiles/game.dir/src/prop.cpp.o
game: CMakeFiles/game.dir/src/font.cpp.o
game: CMakeFiles/game.dir/src/prop_generator.cpp.o
game: CMakeFiles/game.dir/src/bullet.cpp.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/francois/Dev/CppND-Capstone-Shooter/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/francois/Dev/CppND-Capstone-Shooter /home/francois/Dev/CppND-Capstone-Shooter /home/francois/Dev/CppND-Capstone-Shooter/build /home/francois/Dev/CppND-Capstone-Shooter/build /home/francois/Dev/CppND-Capstone-Shooter/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

