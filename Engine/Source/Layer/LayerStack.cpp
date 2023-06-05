#include "LayerStack.h"

namespace Core
{

    LayerStack::LayerStack()
    {
        layerInsert = layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer *layer : layers)
            delete layer;
    }

    void LayerStack::PushLayers(Layer *layer)
    {
        layer->OnAttach();
        layerInsert = layers.emplace(layerInsert, layer);
    }

    void LayerStack::PopLayers(Layer *layer)
    {
        layer->OnDetach();
    }

    void LayerStack::Update()
    {
        for (Layer *layer : layers)
            layer->OnUpdate();
    }

    void LayerStack::RenderImGui()
    {
        for (Layer *layer : layers)
            layer->OnImGuiRender();
    }

}