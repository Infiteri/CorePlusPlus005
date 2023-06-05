#include "Application.h"
#include "Layer/ImGuiLayer.h"
#include "Renderer/OpenGLRenderer.h"
#include "Renderer/Shader.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

// Application instance
static Core::Application *app_inst;

std::string vertexSrc = R"(
        #version 330 core

        layout(location = 0) in vec3 aPosition;

        void main() {
            gl_Position = vec4(aPosition, 1.0);
        };
    )";

std::string fragmentSrc = R"(
        #version 330 core

        layout(location = 0) out vec4 oColor;

        void main() {
            oColor = vec4(1.0, 0.0, 1.0, 1.0);
        };
    )";

static Shader *shader;

namespace Core
{

    Application::Application()
    {
        Engine::Init();
        OpenGLRenderer::Begin();

        window = new Window(1024, 576, "Engine");
        Engine::InitImGui(window);

        shader = new Shader(vertexSrc, fragmentSrc);

        PushLayer(new ImGuiLayer());

        // Gen Buffer
        glGenVertexArrays(1, &va);
        glBindVertexArray(va);

        float vertices[3 * 3] = {
            -0.5f, -0.5f, 0.0f,

            0.5f, -0.5f, 0.0f,

            0.0f, 0.5f, 0.0f};
        Uint indices[3] = {0, 1, 2};

        vertex = new VertexBuffer(vertices, sizeof(vertices));
        index = new IndexBuffer(indices, sizeof(indices));

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

        app_inst = this;
    }

    Application::~Application()
    {
    }

    void Application::PushLayer(Layer *layer)
    {
        layerStack.PushLayers(layer);
    }

    Application *Application::Get()
    {
        return app_inst;
    }

    void Application::Run()
    {
        while (!window->ShouldClose())
        {
            OpenGLRenderer::Render();

            shader->Bind();
            glBindVertexArray(va);
            glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

            Core::Engine::Update(&layerStack);

            window->Display();
        }
    }

    void Application::OnRun()
    {
    }

}