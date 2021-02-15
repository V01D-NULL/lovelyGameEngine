//Graphics libs
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Nuklear GUI
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT
#include "nuklear.h"
#include "nuklear_glfw_gl2.h"

//Other
#include <iostream>
#include <fstream>
#include <string>

#include "core/logging/logging.h"
#include "interface/window.h"
#include "init.h"
#include "main.h"

int main() {
    //Init glfw
    lovely::init initializer;
    initializer.init_glfw();
    
    //Create window
    lovely::Window window(1200, 700, "~lovely~", NULL, NULL);

    initializer.init_glew(); //glew must be initialized after creating a window

    //Poll events
    window.pollEvents();

}

void Main::createVBO() {
    GLuint b = 10;
    glGenBuffers(sizeof(int), &b);
}