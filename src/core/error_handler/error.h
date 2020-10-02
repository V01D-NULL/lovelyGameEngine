#pragma once
#include <string>
#include <GLFW/glfw3.h>

#include "../logging/logging.h"

namespace lovely
{
    namespace error_handler
    {
        class get_GL_error
        {
        public:
            get_GL_error(int error, const char* error_message);
            ~get_GL_error();
        };
    }
}
