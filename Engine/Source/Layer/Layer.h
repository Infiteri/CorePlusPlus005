#pragma once

#include "Core/EngineCore.h"

namespace Core
{

    class CORE_API Layer
    {
    public:
        Layer();
        ~Layer();

        virtual void OnAttach();
        virtual void OnDetach();
        virtual void OnUpdate();
        virtual void OnImGuiRender();
    };
}