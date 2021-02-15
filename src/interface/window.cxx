#include "window.h"
#include <GL/gl.h>


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
        
        //Setting window hints somehow disables the UI from being displayed. That is why there isn't a single window hint function call
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

        //prepare UI
        this->ctx = nk_glfw3_init(this->window, NK_GLFW3_INSTALL_CALLBACKS);
        nk_glfw3_font_stash_begin(&atlas);
        nk_glfw3_font_stash_end();
        this->bg.r = 0.10f, this->bg.g = 0.18f, this->bg.b = 0.24f, this->bg.a = 1.0f;

        //Main loop
        while (!glfwWindowShouldClose(window))
        {   
            glfwPollEvents();
            // this->draw_UI();
            
            glBegin(GL_POLYGON);
                glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
                glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
                glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
            glEnd();
            
        }
    }

    //Any UI changes should go in here
    void Window::draw_UI()
    {
        nk_glfw3_new_frame();
        if (nk_begin(this->ctx, "Lovely UI demo", nk_rect(50, 50, 230, 250),
        NK_WINDOW_BORDER|NK_WINDOW_MOVABLE|NK_WINDOW_SCALABLE|
        NK_WINDOW_MINIMIZABLE|NK_WINDOW_TITLE))
        {
            nk_layout_row_static(this->ctx, 10, 140, 1);
            nk_label(this->ctx, "Hello and welcome :)", NK_TEXT_CENTERED);
            enum {EASY, HARD};
            static int op = EASY;
            static int property = 20;
            nk_layout_row_static(this->ctx, 30, 80, 1);
            if (nk_button_label(this->ctx, "button"))
                lovely::logging::logger::info("Button was pressed", NULL);
            
            nk_layout_row_dynamic(this->ctx, 30, 2);
            if (nk_option_label(this->ctx, "easy", op == EASY)) op = EASY;
            if (nk_option_label(this->ctx, "hard", op == HARD)) op = HARD;
            
            nk_layout_row_dynamic(this->ctx, 25, 1);
            nk_property_int(this->ctx, "Compression:", 0, &property, 100, 10, 1);

            nk_layout_row_dynamic(this->ctx, 20, 1);
            nk_label(this->ctx, "background:", NK_TEXT_LEFT);
            nk_layout_row_dynamic(this->ctx, 25, 1);

            if (nk_combo_begin_color(this->ctx, nk_rgb_cf(bg), nk_vec2(nk_widget_width(ctx),400))) {
                nk_layout_row_dynamic(this->ctx, 120, 1);
                bg = nk_color_picker(this->ctx, bg, NK_RGBA);
                nk_layout_row_dynamic(this->ctx, 25, 1);
                bg.r = nk_propertyf(this->ctx, "#R:", 0, bg.r, 1.0f, 0.01f,0.005f);
                bg.g = nk_propertyf(this->ctx, "#G:", 0, bg.g, 1.0f, 0.01f,0.005f);
                bg.b = nk_propertyf(this->ctx, "#B:", 0, bg.b, 1.0f, 0.01f,0.005f);
                bg.a = nk_propertyf(this->ctx, "#A:", 0, bg.a, 1.0f, 0.01f,0.005f);
                nk_combo_end(this->ctx);
			}
        }
        nk_end(this->ctx);
        glfwGetWindowSize(this->window, &width, &height);
        glViewport(0, 0, this->width, this->height);
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(this->bg.r, this->bg.g, this->bg.b, this->bg.a);
        nk_glfw3_render(NK_ANTI_ALIASING_ON);
        glfwSwapBuffers(this->window);
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
