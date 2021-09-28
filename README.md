# CPPND: Capstone Shooter game

This is my sumbition for udacity capstone project in c++. it's a simple shooter game made with sdl. your goal is to have the highest score possible. my personal best is 62. each time you kill an ennemy. 2 ennemies will spawn

## Controls
- arrow keys to move and change shooting direction while moving.
- hold space to charge your shot. release space to shoot.
- press r to restart 

![image](shooter.gif)

## Project structure 
```bash
.
├── assets                # folder containing resources 
│   ├── fonts             # 
│   └── texture           #
├── cmake                 # build tools
└── src                   # src code
    ├── bot               # bot behaviour encapsulation
    ├── bullet            # bullet physics, rendering
    ├── camera            # camera following player
    ├── collidable        # interface ICollidable used for collision detection 
    ├── constants         # some game contants, folder and file path...
    ├── drawable          # interface IDrawable used for rendering
    ├── event_dispatcher  # 
    ├── font              # wrapper around SDL_font* + some utility method
    ├── game              # class containging all game simulation
    ├── input             # input key definitions
    ├── main              # creating game and running it
    ├── physics           # collision detection betweenn 2 ICollidable
    ├── player            # player behaviour
    ├── prop_generator    # procedural world generation (grass and dirt)
    ├── prop              # simple Drawanle wrapper around a texture 
    ├── renderer          # rendering functionalities 
    ├── spawner           # bot and bullet spawner using CTRP
    ├── spritesheet       # logic around spritesheets
    ├── targerable        # Itargetable interface used by camera and bots to track player
    ├── texture           # wrapper around SDL_Texture pointer
    ├── thread_pool       # pool of thread executing aynchronous tasks
    ├── time              # time functionalites 
    └── vec2              # vector with 2 components and some helper functionalites
```


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./game`.


## Loops Function I/O
| criteria                                                                                       | status             |                                                                                                                      commentary |
| :--------------------------------------------------------------------------------------------- | ------------------ | ------------------------------------------------------------------------------------------------------------------------------: |
| C++ functions and control structures.                                                          | :heavy_check_mark: |                                                                                                                                 |
| The project reads data from a file and process the data, or the program writes data to a file. | :heavy_check_mark: |                                                                                      loading textures and font and rendering it |
| The project accepts user input and processes the input.                                        | :heavy_check_mark: | user input is accesesd through sdl event system then dispatch then processed by player & game class through my own event system |

## Object Oriented Programming
| criteria                                                                                                              |                                    status |
| :-------------------------------------------------------------------------------------------------------------------- | ----------------------------------------: |
| The project uses Object Oriented Programming techniques.                                                              |                        :heavy_check_mark: |
| Classes use appropriate access specifiers for class members.                                                          |                        :heavy_check_mark: |
| Class constructors utilize member initialization lists.                                                               |                        :heavy_check_mark: |
| Classes abstract implementation details from their interfaces.                                                        |                        :heavy_check_mark: |
| Classes encapsulate behavior.                                                                                         |                        :heavy_check_mark: |
| Classes follow an appropriate inheritance hierarchy. & Derived class functions override virtual base class functions. |                        :heavy_check_mark: |
| Overloaded functions allow the same function to operate on different parameters.                                      |                        :heavy_check_mark: |
| Templates generalize functions in the project.                                                                        | [:heavy_check_mark:](src/thread_pool.cpp) |  |

## Memory Management
| criteria                                                                                  |             status |
| :---------------------------------------------------------------------------------------- | -----------------: |
| The project makes use of references in function declarations.                             | :heavy_check_mark: |
| The project uses destructors appropriately.                                               | :heavy_check_mark: |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | :heavy_check_mark: |
| The project follows the Rule of 5.                                                        | :heavy_check_mark: |
| The project uses move semantics to move data, instead of copying it, where possible.      | :heavy_check_mark: |
| The project uses smart pointers instead of raw pointers.                                  | :heavy_check_mark: |
## Concurrency
| criteria                                     |             status |
| :------------------------------------------- | -----------------: |
| The project uses multithreading.             | :heavy_check_mark: |
| A promise and future is used in the project. | :heavy_check_mark: |
| A mutex or lock is used in the project.      | :heavy_check_mark: |
| A condition variable is used in the project. | :heavy_check_mark: |

multithreading is used for infinite procedural props generation. 
It's done asynchrounously when the camera reveal space where prop. A procedural world generation task is then pushed to the thread pool managing all thread synchronisation mechanism.

## Assets
Free assets by [penusbmic](https://www.instagram.com/penusbmic/) and [ansimuz](http://ansimuz.com/site/)


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

The source code is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
