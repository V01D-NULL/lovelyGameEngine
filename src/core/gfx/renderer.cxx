#include "renderer.h"

namespace lovely
{
    namespace core
    {
        namespace gfx
        {
            //Triangle verticies
            lovely::core::Vertex vertices[] = 
            {
                // Position                          //Color
                glm::vec3(0.0f, 0.5f, 0.0f),        glm::vec3(1.f, 0.f, 0.f),
                glm::vec3(-0.5f, -0.5f, 0.0f),      glm::vec3(0.f, 1.f, 0.f),
                glm::vec3(0.5f, -0.5f, 0.0f),       glm::vec3(0.f, 0.f, 1.f)
            };

            unsigned number_of_vertices = sizeof(vertices) / sizeof(lovely::core::Vertex);
            unsigned number_of_indicies = sizeof(lovely::core::indicies) / sizeof(GLuint);

            
            void Renderer::VAO()
            {
                lovely::logging::logger::info(__FILE__, "test", NULL);
            }
        }
    }
}