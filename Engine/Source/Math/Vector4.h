#pragma once


namespace Core
{
    class Vector4
    {
    public:
        Vector4(float x, float y, float z, float w);
        ~Vector4();

        int x;
        int y;
        int z;
        int w;
    };

}