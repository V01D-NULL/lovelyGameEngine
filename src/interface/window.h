#pragma once

#include "../core/logging/logging.h"
#include "events.h"
#include <string>
#include <iostream>



namespace lovely {
    class Window {
    public:
        Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share); //Last two can be NULL
        ~Window();
        void pollEvents();

    private:
        GLFWwindow* window;
    };
}
