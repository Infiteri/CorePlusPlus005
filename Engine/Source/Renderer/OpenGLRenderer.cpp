#include "OpenGLRenderer.h"
#include "glad/glad.h"

namespace Core
{

    void OpenGLRenderer::Begin()
    {
    }
    void OpenGLRenderer::ClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void OpenGLRenderer::ClearColor(Vector4 *vector)
    {
        ClearColor(vector->x, vector->y, vector->z, vector->w);
    }

    void OpenGLRenderer::Render()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void OpenGLRenderer::End()
    {
    }
}