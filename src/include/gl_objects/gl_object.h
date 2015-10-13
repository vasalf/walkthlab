#ifndef GOBJ_GL_OBJECT_H_
#define GOBJ_GL_OBJECT_H_

#include <stddef.h>

#include <GL/gl.h>

#include <vector_math.h>

typedef struct
{
    size_t n;
    size_t* m;
    vect3f* colors;
    GLuint* VBOs;
} gl_object;

void draw_gl_object(gl_object obj);

gl_object make_empty_gl_object(size_t n);
void free_gl_object(gl_object obj);

#endif //GOBJ_GL_OBJECT_H_
