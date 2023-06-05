#include "ImGuiLayer.h"
#include "Renderer/OpenGLRenderer.h"

static float bg[4] = {0.0f, 0.0f, 0.0f, 1.0f};

namespace Core
{

    void ImGuiLayer::OnImGuiRender()
    {
        ImGui::Begin("Hello ImGuiLayer");
        ImGui::ColorEdit4("Background", bg, ImGuiColorEditFlags_NoInputs);

        // Change BG
        OpenGLRenderer::ClearColor(bg[0], bg[1], bg[2], bg[3]);

        ImGui::End();
    }
}