/* events.cxx - Event handler. Callbacks are handled here*/

#include "events.h"

namespace lovely {
    namespace events {
        //Handle closing events
        static void Events::E_closing_callback(GLFWwindow* window) {
            /*
                Window closing callback

                @return void
                @param GLFWwindow*
                --
                = For now just log, in the future a dialog box will pop-up asking for confirmation.
            */
            lovely::logging::logger::info("Window is closing", NULL);
        }

        //Handle resize events
        static void Events::E_resize_callback(GLFWwindow* window, int width, int height) {
            /*
                Window resize callback

                @return void
                @param GLFWwindow*, 2 int's (width, height)
                --
                = Print the new width and height
                = Adjust the viewport (This avoids stretching and tearing of objects in the scene)
            */
            std::string w, h;
            w = std::to_string(width);
            h = std::to_string(height);
            lovely::logging::logger::info(" Width: ", w.c_str(), "Height: ", h.c_str(), NULL);
            glViewport(0, 0, width, height);
        }

        //Handle keyboard input events
        static void Events::E_input(GLFWwindow* window, int key, int scancode, int action, int mods) {
            /*
                Keyboard callback

                @return void
                @param GLFWwindow*, 4 int's
                --
                = Scan for the escape key, and close the window if it has been pressed. (Add a better polling implementation in the future (https://www.youtube.com/results?search_query=glfw+polling+keyboard+input))
            */
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
}