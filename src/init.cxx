//Initialize basic libs
#include "init.h"
#include "core/logging/logging.h"

namespace lovely {
    
    void init::init_glfw()
    {
        /*
        */
        lovely::logging::logger::info(__FILE__, "Initializing glfw...", NULL);
    
        if (!glfwInit())
        {
            lovely::logging::logger::err(__FILE__, "Could not initialize glfw.", NULL);
            exit(EXIT_FAILURE);
        }
        else
            lovely::logging::logger::info(__FILE__, "Success", NULL);
        
    }
    
    void init::init_glew()
    {
        lovely::logging::logger::info(__FILE__, "Initializing glew...", NULL);

        GLenum status = glewInit();
        if (GLEW_OK != status)
        {
            lovely::logging::logger::err(__FILE__, "Error initializing GLEW! -->", glewGetErrorString(status), NULL);
        }
        else
            lovely::logging::logger::info(__FILE__, "Success", NULL);
    }
}
