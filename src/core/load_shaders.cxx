#include "load_shaders.h"

namespace lovely {
    namespace GL {
        bool Shader::load_basic_shaders(GLuint program, std::string vertex_shader_src, std::string fragment_shader_src)
        {
            /*
                Load a shader and pass it to the GPU

                @return bool (True on success, false if failed)
                @param GLuint, string (path to shader)
                --
                = Create some variables to keep track of the state of operations
                = Open the file and write it's data into a std::string data type
            */
            lovely::logging::logger::info("Loading shader:", vertex_shader_src.c_str(), NULL);

            char shader_loading_log[LOG_BUFFER_SIZE];   //OpenGL will write any errors or warnings to this char array
            bool state_of_shader = false;               //Return value of the function. True if successfull
            GLint status;                               //Status of compilation or linkage. Used by `glGetShaderiv();`
            
            std::string temp = "";
            std::string src = "";

            //Read from file
            std::ifstream in_file;

            in_file.open(vertex_shader_src);
            if (in_file.is_open()) 
            {
                while (std::getline(in_file, temp))
                {
                    src += temp.append("\n"); //Write current line to `src` and append a newline to it.
                }
            }
            else { lovely::logging::logger::err("Could not open the shader, thus the file cannot be parsed. (Perhaps double check your spelling?)", NULL); return state_of_shader = false;}
            in_file.close();

            /* Pass all the info to OpenGL */
            
            // !!!! MOVE THE THINGS THAT WONT COMPILE TO MAIN.CXX !!!!

            // GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);        //Create the shader using OpenGL
            // const GLchar* vertex_shader_src = src.c_str();                  //Format the src string to fit openGL
            // glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);     //Set the source file for OpenGL
            // glCompileShader(vertex_shader);                                 //Tell OpenGL to compile the shader
            // glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);      //Check for errors

            return state_of_shader = true;
        }
    }
}