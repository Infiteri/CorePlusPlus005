#pragma once

#include "Math/Matrix4x4.h"
#include "Math/Vector4.h"

namespace Core
{

    class OpenGLRenderer
    {
    public:
        OpenGLRenderer();
        ~OpenGLRenderer();

        static void Begin();

        static void ClearColor(float r, float g, float b, float a);
        static void ClearColor(Vector4 *vector);

        static void Render();

        static void End();
    };

}