#pragma once

#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "../core/logging/logging.h"

//https://stackoverflow.com/questions/1000663/using-a-c-class-member-function-as-a-c-callback-function
namespace lovely {
    namespace events {
        class Events {
            public:
                static void E_closing_callback(GLFWwindow* window);
                static void E_resize_callback(GLFWwindow* window, int width, int height);
                static void E_input(GLFWwindow* window, int key, int scancode, int action, int mods);
        };
    }
}