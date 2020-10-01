#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "core/logging/logging.h"

int main() {
    if (!glfwInit())
    {
        std::cout << "Error\n";
    }
    else
        std::cout << "Success\n";

    lovely::logging::logger::info("test", NULL);
    lovely::logging::logger::warn("test", NULL);
    lovely::logging::logger::err("test", NULL);
}
