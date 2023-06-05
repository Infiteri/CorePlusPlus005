#include "Matrix4x4.h"

namespace Core
{

    Matrix4x4::Matrix4x4()
    {
        data[0] = 1.0f;
        data[5] = 1.0f;
        data[10] = 1.0f;
        data[15] = 1.0f;
    }

    void Matrix4x4::Translate(float x, float y, float z)
    {
        data[13] = x;
        data[14] = y;
        data[15] = z;
    }
}