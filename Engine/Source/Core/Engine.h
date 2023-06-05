#pragma once

#include "Window.h"
#include "Layer/LayerStack.h"
#include "glm/glm.hpp"

namespace Core
{

    class Engine
    {
    public:
        Engine();
        ~Engine();

        /// @brief Starts the vendor needs (ImGui, GLFW Glad)
        static void Init();
        static void InitImGui(Window *window);

        static void Update(LayerStack *stack);
    };

}