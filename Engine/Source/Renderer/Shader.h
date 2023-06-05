#pragma once

#include <string>
#include <glad/glad.h>

class Shader
{
public:
    Shader(const std::string &vertexSrc, const std::string &fragmentSrc);
    ~Shader();

    /// @brief Binds the current shader
    void Bind();

    /// @brief Unbinds the current shader
    void Unbind();



    GLuint CreateShader(const std::string &source, GLenum type);

private:
    uint32_t program;
};
