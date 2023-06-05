#pragma once

#include "EngineCore.h"
#include "Window.h"
#include "Engine.h"
#include "Renderer/Buffer.h"
#include "Layer/LayerStack.h"

namespace Core
{

    class CORE_API Application
    {
    private:
        LayerStack layerStack;

    public:
        Window *window;
        Application();
        ~Application();

        void PushLayer(Layer *layer);

        static Application *Get();

        void Run();
        virtual void OnRun();

        // buffers
        unsigned int va, vb, ib;

        VertexBuffer *vertex;
        IndexBuffer *index;
    };

    // Definition for the create app in entry point.
    // Note that the entry point is handled by the engine (Core/EntryPoint.h) which defines a extern Core::CreateApplication() which is also
    // defined here  so that the engine knows how to handle it.
    Application *CreateApplication();
}