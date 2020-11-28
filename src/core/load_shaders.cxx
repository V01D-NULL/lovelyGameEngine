#include "load_shaders.h"

bool Shader::load_shader(GLuint program, const char *shader_src)
{
    /*
        Load a shader and pass it to the GPU

        @return bool (True on success, false if failed)
        @param GLuint, string (path to shader)
        --
    */
    bool state_of_shader = false; //Return value of the function. True if successfull
    std::cout << "Loading shader ( " << shader_src << ')\n';
    // lovely::logging::logger::info("Loading shader ( ", shader_src, ')', NULL);

    return state_of_shader;
}