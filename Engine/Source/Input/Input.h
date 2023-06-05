#pragma once

#include "Core/EngineCore.h"
#include <unordered_map>

namespace Core
{

    class CORE_API Input
    {
    public:
        Input();
        ~Input();

        static bool IsKeyPressed(int keycode);
        static void HandleKeyDown(int keycode);
        static void HandleKeyUp(int keycode);
    };

}