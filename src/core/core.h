#pragma once

#include <GL/gl.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace lovely
{
    namespace core
    {
        struct Vertex
        {
            glm::vec3 position;
            glm::vec3 color;
            glm::vec2 textcoord;
        };

        const GLuint indicies[] =
        {
            0, 1, 2
        };

    }
}