#pragma once
#include "input.hpp"

enum KeyState{
    pressed,
    released
};

struct KeyEvent {
    Key key;
    KeyState key_state;
};