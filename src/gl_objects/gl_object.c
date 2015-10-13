#include <stddef.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/gl.h>

#include <gl_render.h>
#include <gl_objects/gl_object.h>

void draw_gl_object(gl_object obj)
{
    for (size_t i = 0; i < obj.n; i++)
    {
        glUniform3f(gl_uniforms.color_location, obj.colors[i].x, obj.colors[i].y, obj.colors[i].z);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[i]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_POLYGON, 0, obj.m[i]);

        glDisableVertexAttribArray(0);
    }
}

gl_object make_empty_gl_object(size_t n)
{
    gl_object obj;
    obj.n = n;
    obj.colors = malloc(n * sizeof(vect3f));
    for (size_t i = 0; i < n; i++)
        obj.colors[i] = make_vect3f(1.0, 0.0, 0.0);
    obj.m = calloc(sizeof(size_t), n);
    obj.VBOs = calloc(sizeof(GLuint), n);
    glGenBuffers(n, obj.VBOs);
    return obj;
}

void free_gl_object(gl_object obj)
{
    glDeleteBuffers(obj.n, obj.VBOs);
    free(obj.colors);
    free(obj.m);
}
