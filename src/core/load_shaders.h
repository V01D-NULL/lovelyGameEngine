#pragma once

#include <fstream>
#include "./logging/logging.h"
#include <GLFW/glfw3.h>

class Shader {
    public:
        bool load_shader(GLuint program, const char *shader_src);
};