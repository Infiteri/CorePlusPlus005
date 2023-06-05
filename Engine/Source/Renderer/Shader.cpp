#include "Shader.h"
#include "Core/Logger.h"

#include <vector>

Shader::Shader(const std::string &vertexSrc, const std::string &fragmentSrc)
{
    GLuint vertexShader = CreateShader(vertexSrc, GL_VERTEX_SHADER);
    GLuint fragmentShader = CreateShader(fragmentSrc, GL_FRAGMENT_SHADER);

    // Gen program
    program = glCreateProgram();

    // Attach our shaders to our program
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    // Link our program
    glLinkProgram(program);

    // Note the different functions here: glGetProgram* instead of glGetShader*.
    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

        // We don't need the program anymore.
        glDeleteProgram(program);
        // Don't leak shaders either.
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        CORE_ERROR("Program dead.");
        CORE_ERROR("%s", infoLog.data());
    }
}

Shader::~Shader()
{
}

void Shader::Bind()
{
    glUseProgram(this->program);
}

void Shader::Unbind()
{
    glUseProgram(0);
}

GLuint Shader::CreateShader(const std::string &source, GLenum type)
{
    GLuint shader = glCreateShader(type);
    const GLchar *newSource = (const GLchar *)source.c_str();
    glShaderSource(shader, 1, &newSource, 0);
    glCompileShader(shader);

    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        // The maxLength includes the NULL character
        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

        CORE_ERROR("Shader compilation failed.");
        CORE_ERROR("%s", infoLog.data());

        // We don't need the shader anymore.
        glDeleteShader(shader);

        // Use the infoLog as you see fit.

        // In this simple program, we'll just leave
        return (GLuint)0;
    }

    return shader;
}
