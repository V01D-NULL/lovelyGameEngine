//Graphics libs
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

//Other
#include <iostream>
#include <fstream>
#include <string>

#include "core/logging/logging.h"
#include "interface/window.h"
#include "core/core.h"
#include "init.h"
#include "main.h"

int main() {
    //Init glfw
    lovely::init initializer;
    initializer.init_glfw();
    
    //Create window
    lovely::Window window = lovely::Window(1200, 700, "~lovely~", NULL, NULL);

    initializer.init_glew(); //glew must be initialized after creating a window

    //Poll events
    window.pollEvents();

}

void Main::createVBO() {
    GLuint b = 10;
    glGenBuffers(sizeof(int), &b);
}