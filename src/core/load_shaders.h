#pragma once

#include <fstream>
#include <GLFW/glfw3.h>
#include <string>
#include "./logging/logging.h"


namespace lovely {
    namespace GL {
        class Shader {
            public:
                bool load_basic_shaders(GLuint program, const char *vertex_shader_src, const char *fragment_shader_src);
            private:
                const unsigned int LOG_BUFFER_SIZE = 512; //The size of the buffer which OpenGL will write any errors or warnings to while working with the shader
        };
    }
}