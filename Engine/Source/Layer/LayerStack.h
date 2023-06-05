#pragma once

#include "Core/EngineCore.h"
#include "Layer.h"

#include <vector>

namespace Core
{

    class CORE_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        void PushLayers(Layer *layer);
        void PopLayers(Layer *layer);

        void Update();
        void RenderImGui();

        std::vector<Layer *>::iterator begin() { return layers.begin(); };
        std::vector<Layer *>::iterator end() { return layers.end(); };

    private:
        std::vector<Layer *> layers;
        std::vector<Layer *>::iterator layerInsert;
    };

}