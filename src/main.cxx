#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <SOIL.h>

#include "core/logging/logging.h"
#include "interface/window.h"

int main() {
    lovely::logging::logger::info("Initializing glfw...", NULL);
    
    if (!glfwInit())
    {
        lovely::logging::logger::err("Could not initialize glfw.", NULL);
        return -1;
    }
    else
        lovely::logging::logger::info("Success", NULL);
    
    lovely::Window(900, 700, "~lovely~", NULL, NULL);
    
    
    while (1);
}
