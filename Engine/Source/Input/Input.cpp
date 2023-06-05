#include "Input.h"

static std::unordered_map<int, bool> keys;

namespace Core
{

    bool Input::IsKeyPressed(int keycode)
    {
        return keys[keycode];
    }

    void Input::HandleKeyDown(int keycode)
    {
        keys[keycode] = true;
    }
    void Input::HandleKeyUp(int keycode)
    {
        keys[keycode] = false;
    }
}