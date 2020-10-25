//Graphics libs
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Other
#include <iostream>
#include <string>

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
    
    glewInit();
    
    while (1);
}
