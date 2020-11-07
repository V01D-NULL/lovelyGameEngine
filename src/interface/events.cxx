/* events.cxx - Event handler (among other) callbacks are handled here*/
#include "events.h"

//Handle closing events
static void Events::E_closing_callback(GLFWwindow* window) {
    lovely::logging::logger::info("Window is closing", NULL);
}

//Handle resize events
static void Events::E_resize_callback(GLFWwindow* window, int width, int height) {
    std::string w, h;
    w = std::to_string(width);
    h = std::to_string(height);
    lovely::logging::logger::info(" Width: ", w.c_str(), "Height: ", h.c_str(), NULL);
    glViewport(0, 0, width, height);
}

//Handle keyboard input events
static void Events::E_input() {

}