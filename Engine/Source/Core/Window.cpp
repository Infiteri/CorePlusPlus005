#include "Window.h"
#include "Input/Input.h"

namespace Core
{

    Window::Window(int width, int height, String *title)
    {
        // Assign values
        this->width = width;
        this->height = height;
        this->title = title;

        // Setup GLFW window handle
        handle = glfwCreateWindow(width, height, title, NULL, NULL);
        glfwMakeContextCurrent(handle);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); // ! AFTER MAKING CONTEXT CURRENT

        // Setup keys
        glfwSetKeyCallback(handle, [](GLFWwindow *window, int key, int scancode, int action, int mods)
                           {
            switch(action) {
                case GLFW_PRESS:
                Input::HandleKeyDown(key);
                break;
                case GLFW_RELEASE:
                Input::HandleKeyUp(key);
                break;

            } });
    }

    Window::~Window()
    {
        glfwDestroyWindow(handle);
    }

    void Window::Display()
    {
        glfwPollEvents();
        glfwSwapBuffers(handle);

        glfwGetWindowSize(handle, &width, &height);
    }

    bool Window::ShouldClose()
    {
        return glfwWindowShouldClose(handle);
    }

    void Window::SetVSync(bool value)
    {
        if (value == true)
        {
            glfwSwapInterval(1);
        }
        else
        {
            glfwSwapInterval(0);
        };
    }

}