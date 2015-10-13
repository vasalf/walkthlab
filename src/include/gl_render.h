#ifndef GL_RENDER_H_
#define GL_RENDER_H_

#include <GLFW/glfw3.h>

struct
{
    GLuint rotate_location;
    GLuint color_location;
    GLuint window_location;
} gl_uniforms;

struct
{
    int height, width;
} window_size;

void create_vbo();
void render(GLFWwindow* window);

#endif //GL_RENDER_H_
