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
#include "init.h"

int main() {
    //Init glfw
    lovely::init initializer;
    initializer.init_glfw();
    
    //Create window
    lovely::Window(700, 900, "~lovely~", NULL, NULL);
    
    initializer.init_glew(); //glew must be initialized after creating a window
    
    
}
