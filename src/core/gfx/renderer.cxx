#include "renderer.h"

namespace lovely
{
    namespace gfx
    {
        //Triangle verticies
        lovely::core::Vertex vertices[] = 
        {
            // Position                          //Color
            glm::vec3(0.0f, 0.5f, 0.0f),        glm::vec3(1.f, 0.f, 0.f),
            glm::vec3(-0.5f, -0.5f, 0.0f),      glm::vec3(0.f, 1.f, 0.f),
            glm::vec3(0.5f, -0.5f, 0.0f),       glm::vec3(0.f, 0.f, 1.f),
        };

        unsigned number_of_indicies = sizeof(vertices) / sizeof(lovely::core::Vertex);
    }
}