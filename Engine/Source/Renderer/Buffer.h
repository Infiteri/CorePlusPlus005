#pragma once

#include "Core/EngineCore.h"

namespace Core
{
    //? -- VERTEX ---------

    class VertexBuffer
    {
    private:
        Uint id;

    public:
        VertexBuffer(float *vertices, Uint size);
        ~VertexBuffer();

        void Bind();
        void Unbind();
    };

    //? -- INDEX ----------

    class IndexBuffer
    {
    private:
        Uint id;

    public:
        IndexBuffer(Uint *indices, Uint size);
        ~IndexBuffer();

        void Bind();
        void Unbind();
    };

}