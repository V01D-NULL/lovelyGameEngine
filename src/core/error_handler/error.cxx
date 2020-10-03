#include "error.h"

namespace lovely {
    namespace error_handler {
        
        void error_handler_callback(int error, const char* error_description)
        {
            //Convert int to string
            std::string error_string = std::to_string(error);
            //Log error message
            lovely::logging::logger::err(error_description, error_string.c_str(), NULL);
        }
        
        get_GL_error::get_GL_error(int error, const char* error_message)
        {
            glfwSetErrorCallback(error_handler_callback);
        }

        get_GL_error::~get_GL_error()
        {
            glfwTerminate();
        }
    }
}
