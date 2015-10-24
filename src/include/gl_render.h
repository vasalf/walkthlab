#ifndef GL_RENDER_H_
#define GL_RENDER_H_

#include <GLFW/glfw3.h>

#include <gl_objects/gl_object.h>
#include <oneway_list.h>

typedef struct
{
    GLuint rotate_location;
    GLuint color_location;
    GLuint window_location;
    GLuint camera_location; 
} gl_uniforms_struct;

extern gl_uniforms_struct gl_uniforms;

typedef struct
{
    int height, width;
} window_size_struct;

extern window_size_struct window_size;

extern oneway_gl_object_ptr_list to_draw;

void render(GLFWwindow* window);

#endif //GL_RENDER_H_
