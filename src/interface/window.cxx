#include "window.h"

namespace lovely {
    Window::Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share)
    {
        lovely::logging::logger::info("Creating window", NULL);
        
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        
        //Needed by apple devices
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
            
        window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
        
        if (!window || window == NULL) 
        {
            std::string result;
            lovely::logging::logger::err("Could not create window!\nAbort? (y/n) ", NULL);
            std::cin >> result;
            if (result == "y")
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            else
                return;
        }
        glfwMakeContextCurrent(window);
        glViewport(0, 0, width, height);
    }
    
    void Window::pollEvents() {
        //Setup event handlers
        Events lovely_events;
        glfwSetWindowCloseCallback(window, lovely_events.E_closing_callback);
        glfwSetWindowSizeCallback(window, lovely_events.E_resize_callback);
        glfwSetKeyCallback(window, lovely_events.E_input);

        //Main loop
        while (!glfwWindowShouldClose(window))
        {   
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    Window::~Window()
    {
        lovely::logging::logger::info("~window", NULL);
    }
}
