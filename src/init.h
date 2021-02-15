#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace lovely {
    class init {
    public:
        void init_glfw();
        void init_glew();
    };
}
