#include <stddef.h>

#include <GL/glew.h>
#include <GL/gl.h>

#include <gl_objects/gl_object.h>
#include <gl_objects/cuboid.h>

gl_object make_cuboid(vect3f p, vect3f diag)
{
    gl_object obj = make_empty_gl_object(6);
    for (int i = 0; i < 6; i++)
        obj.m[i] = 4;
    vect3f panel[4];
    //front
    panel[0] = p;
    panel[1] = make_vect3f(p.x + diag.x, p.y, p.z);
    panel[2] = make_vect3f(p.x + diag.x, p.y + diag.y, p.z);
    panel[3] = make_vect3f(p.x, p.y + diag.y, p.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
    //left
    panel[0] = p;
    panel[1] = make_vect3f(p.x, p.y + diag.y, p.z);
    panel[2] = make_vect3f(p.x, p.y + diag.y, p.z + diag.z);
    panel[3] = make_vect3f(p.x, p.y, p.z + diag.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
    //lower
    panel[0] = p;
    panel[1] = make_vect3f(p.x, p.y, p.z + diag.z);
    panel[2] = make_vect3f(p.x + diag.x, p.y, p.z + diag.z);
    panel[3] = make_vect3f(p.x + diag.x, p.y, p.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
    //back
    panel[0] = make_vect3f(p.x + diag.x, p.y + diag.y, p.z + diag.z);
    panel[1] = make_vect3f(p.x + diag.x, p.y, p.z + diag.z);
    panel[2] = make_vect3f(p.x, p.y, p.z + diag.z);
    panel[3] = make_vect3f(p.x, p.y + diag.y, p.z + diag.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
    //right
    panel[0] = make_vect3f(p.x + diag.x, p.y + diag.y, p.z + diag.z);
    panel[1] = make_vect3f(p.x + diag.x, p.y + diag.y, p.z);
    panel[2] = make_vect3f(p.x + diag.x, p.y, p.z);
    panel[3] = make_vect3f(p.x + diag.x, p.y, p.z + diag.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
   //top
    panel[0] = make_vect3f(p.x + diag.x, p.y + diag.y, p.z + diag.z);
    panel[1] = make_vect3f(p.x + diag.x, p.y, p.z + diag.z);
    panel[2] = make_vect3f(p.x, p.y, p.z + diag.z);
    panel[3] = make_vect3f(p.x, p.y + diag.y, p.z + diag.z);
    glBindBuffer(GL_ARRAY_BUFFER, obj.VBOs[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(panel), panel, GL_STATIC_DRAW);
    return obj;
}

