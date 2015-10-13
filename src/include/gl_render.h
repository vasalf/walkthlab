#ifndef GL_RENDER_H_
#define GL_RENDER_H_

#include <GLFW/glfw3.h>

struct
{
    GLuint rotate_location;
} gl_uniforms;

void create_vbo();
void render(GLFWwindow* window);

#endif //GL_RENDER_H_
