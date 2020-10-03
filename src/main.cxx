#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "core/logging/logging.h"
#include "interface/window.h"

//test

int main() {
    lovely::logging::logger::info("Initializing glfw...", NULL);
    
    if (!glfwInit())
    {
//         lovely::errorHanlder::getGLError();
        lovely::logging::logger::err("Could not initialize glfw.", NULL);
        return -1;
    }
    else
        lovely::logging::logger::info("Success", NULL);
    
    std::string msg = "test";
    std::string conv = std::to_string(10);
    lovely::logging::logger::err(msg.c_str(), conv.c_str(), NULL);
}
