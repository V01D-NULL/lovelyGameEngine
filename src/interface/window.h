#pragma once

#include "../core/logging/logging.h"
#include "events.h"
#include "../main.h"
#include "../core/load_shaders.h"
#include <string>
#include <iostream>



namespace lovely {
    class Window {
    //Constructor / Destructor
    public:
        Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share); //Last two can be NULL
        ~Window();
    //Public function
    public:
        void pollEvents();
        void load_shaders();

    private:
        GLFWwindow* window;
    };
}
