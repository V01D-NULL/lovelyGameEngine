#include "window.h"

namespace lovely {
    Window::Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share)
    {
        lovely::logging::logger::info("window", NULL);
        
        window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
        
        if (window || window == NULL) 
        {
            std::string result;
            lovely::logging::logger::err("Could not create window!\nAbort? (y/n) ", NULL);
            std::cin >> result;
            if (result == "y")
                exit(EXIT_FAILURE);
            else
                return;
        }
        
    }

    Window::~Window()
    {
        lovely::logging::logger::info("~window", NULL);
    }
}
