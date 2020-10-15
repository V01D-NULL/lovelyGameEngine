#pragma once

#include "../core/logging/logging.h"
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>

namespace lovely {
    class Window {
    public:
        Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share); //Last two can be NULL
        ~Window();
        
    private:
        GLFWwindow* window;
    };
}
