#pragma once


namespace Core
{

    class Matrix4x4
    {
    public:
        Matrix4x4();
        ~Matrix4x4();

        float data[16] = {
            1.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 0.0f,

            0.0f, 0.0f, 1.0f, 0.0f,

            0.0f, 0.0f, 0.0f, 1.0f};

        void Translate(float x, float y, float z);
    };

}