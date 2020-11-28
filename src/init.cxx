//Initialize basic libs
#include "init.h"
#include "core/logging/logging.h"

namespace lovely {
    
    void init::init_glfw()
    {
        /*
        */
        lovely::logging::logger::info("Initializing glfw...", NULL);
    
        if (!glfwInit())
        {
            lovely::logging::logger::err("Could not initialize glfw.", NULL);
            exit(EXIT_FAILURE);
        }
        else
            lovely::logging::logger::info("Success", NULL);
        
    }
    
    void init::init_glew()
    {
        lovely::logging::logger::info("Initializing glew...", NULL);

        GLenum status = glewInit();
        if (GLEW_OK != status)
        {
            lovely::logging::logger::err("Error initializing GLEW! -->", glewGetErrorString(status), NULL);
        }
        else
            lovely::logging::logger::info("Success", NULL);
    }
}
