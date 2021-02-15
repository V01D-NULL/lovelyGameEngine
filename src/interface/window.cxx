#include "window.h"

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_GLFW_GL2_IMPLEMENTATION
#define NK_KEYSTATE_BASED_INPUT
#include "../nuklear.h"
#include "../nuklear_glfw_gl2.h"

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
        this->width = width;
        this->height = height;
            
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
        glfwGetWindowSize(window, &width, &height);
        // glViewport(0, 0, width, height);
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
        // lovely::events::Events lovely_events;
        // glfwSetWindowCloseCallback(window, lovely_events.E_closing_callback);
        // glfwSetWindowSizeCallback(window, lovely_events.E_resize_callback);
        // glfwSetKeyCallback(window, lovely_events.E_input);

        // main.createVBO();
        // load_shaders();

        //Main loop
        struct nk_context *ctx;
        struct nk_colorf bg;
        ctx = nk_glfw3_init(this->window, NK_GLFW3_INSTALL_CALLBACKS);
        struct nk_font_atlas *atlas;
        nk_glfw3_font_stash_begin(&atlas);
        nk_glfw3_font_stash_end();
        bg.r = 0.10f, bg.g = 0.18f, bg.b = 0.24f, bg.a = 1.0f;
        while (!glfwWindowShouldClose(window))
        {   
            // glClear(GL_COLOR_BUFFER_BIT);
            // glfwSwapBuffers(window);
            glfwPollEvents();
            nk_glfw3_new_frame();
            if (nk_begin(ctx, "Demo", nk_rect(50, 50, 230, 250),
            NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
            NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
            {
                enum {EASY, HARD};
                static int op = EASY;
                static int property = 20;
                nk_layout_row_static(ctx, 30, 80, 1);
                if (nk_button_label(ctx, "button"))
                    lovely::logging::logger::info("Button was pressed", NULL);
                
                nk_layout_row_dynamic(ctx, 30, 2);
                if (nk_option_label(ctx, "easy", op == EASY)) op = EASY;
                if (nk_option_label(ctx, "hard", op == HARD)) op = HARD;

                nk_layout_row_dynamic(ctx, 25, 1);
                nk_property_int(ctx, "Compression:", 0, &property, 100, 10, 1);

                nk_layout_row_dynamic(ctx, 20, 1);
                nk_label(ctx, "background:", NK_TEXT_LEFT);
                nk_layout_row_dynamic(ctx, 25, 1);

                if (nk_combo_begin_color(ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
                    nk_layout_row_dynamic(ctx, 120, 1);
                    bg = nk_color_picker(ctx, bg, NK_RGBA);
                    nk_layout_row_dynamic(ctx, 25, 1);
                    bg.r = nk_propertyf(ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
                    bg.g = nk_propertyf(ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
                    bg.b = nk_propertyf(ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
                    bg.a = nk_propertyf(ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
                    nk_combo_end(ctx);
			    }
            }
            nk_end(ctx);
            glfwGetWindowSize(this->window, &width, &height);
            glViewport(0, 0, this->width, this->height);
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(bg.r, bg.g, bg.b, bg.a);
            nk_glfw3_render(NK_ANTI_ALIASING_ON);
            glfwSwapBuffers(this->window);
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
