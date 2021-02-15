#pragma once

#include "../core/logging/logging.h"
#include "events.h"
#include "../main.h"
#include "../core/load_shaders.h"
#include <string>
#include <iostream>

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
    class Window {
    //Constructor / Destructor
    public:
        Window(int width, int height, std::string title, GLFWmonitor* monitor, GLFWwindow* share); //Last two can be NULL
        ~Window();
    //Public function
    public:
        void pollEvents();
        void load_shaders();
        void draw_UI();
    private:
        GLFWwindow *window;
        struct nk_colorf bg;
        struct nk_context *ctx;
        struct nk_font_atlas *atlas;
        int width;
        int height;
	    
    };
}
