#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit())
    {
        std::cout << "Error\n";
    }
    else
        std::cout << "Success\n";
}
