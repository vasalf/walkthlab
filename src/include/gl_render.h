#ifndef GL_RENDER_H_
#define GL_RENDER_H_

#include <GLFW/glfw3.h>

#include <gl_objects/gl_object.h>

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

extern gl_object cube;

void render(GLFWwindow* window);

#endif //GL_RENDER_H_
