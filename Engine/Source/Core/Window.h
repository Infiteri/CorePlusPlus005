#pragma once

#include "EngineCore.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Core
{

    class CORE_API Window
    {
    private:
    public:
        int width;
        int height;
        String *title;

        GLFWwindow *handle;

        Window(int width, int height, String *title);
        ~Window();

        // @brief This function swaps the buffers of the glfw handle and polls the events
        void Display();

        // Note that the engine must run only while the window doesn't send a close request
        bool ShouldClose();

        /// @brief Sets the VSync to the value set
        void SetVSync(bool value);
    };

}