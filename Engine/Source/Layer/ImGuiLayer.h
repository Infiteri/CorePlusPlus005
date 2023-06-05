#pragma once
#include "Layer/Layer.h"
#include "imgui.h"

namespace Core
{

    class ImGuiLayer : public Core::Layer
    {
    public:
        void OnImGuiRender();
    };
}