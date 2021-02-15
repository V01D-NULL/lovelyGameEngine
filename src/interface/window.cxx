#include "window.h"

namespace lovely {
    Window::Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share)
    {
        /*
            Default constructor (Creates a window)

            @return void
            @param int (width), int (height), string (title), GLFWmonitor*, GLFWwindow*
            --
            = Set some options (WindowHint)
            = Create the window
            = Catch any errors
            = Adjust the viewport
        */
        lovely::logging::logger::info("Creating window", NULL);
        
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
        
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
        /*
            Poll for events / init the main loop

            @return void
            @param none
            --
            = Set function callbacks
            = Enter main loop, poll events, render, etc...
        */
        Main main;
        //Setup event handlers
        lovely::events::Events lovely_events;
        glfwSetWindowCloseCallback(window, lovely_events.E_closing_callback);
        glfwSetWindowSizeCallback(window, lovely_events.E_resize_callback);
        glfwSetKeyCallback(window, lovely_events.E_input);

        // main.createVBO();
        load_shaders();
        //Main loop
        while (!glfwWindowShouldClose(window))
        {   
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    void Window::load_shaders() {
        /*
            Load some basic shaders

            @return void
            @param none
            --
            = Load shaders
        */
        lovely::GL::Shader shader;
        GLuint program;
        std::string vertex_core = "src/GL/shaders/vertex_core.glsl";
        std::string fragment_core = "src/GL/shaders/fragment_core.glsl";
        if (!shader.load_basic_shaders(program, vertex_core, fragment_core))
        {
            lovely::logging::logger::err("Function `load_shader` returned false!", NULL);
        }
    }

    Window::~Window()
    {
        /*
            Deconstructor
        */
        lovely::logging::logger::info("~window", NULL);
    }
}
