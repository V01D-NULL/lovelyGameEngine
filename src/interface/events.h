#pragma once

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "../core/logging/logging.h"

class Events {
    public:
        static void E_closing_callback(GLFWwindow* window);
        static void E_resize_callback(GLFWwindow* window, int width, int height);
        static void E_input();
};