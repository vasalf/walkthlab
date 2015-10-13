#ifndef GOBJ_CUBOID_H_
#define GOBJ_CUBOID_H_

#include <gl_objects/gl_object.h>
#include <vector_math.h>

/* Cuboid faces order is:
 * 0 - the front face
 * 1 - the left face
 * 2 - the lower face
 * 3 - the back face
 * 4 - the right face
 * 5 - the top face
*/

gl_object make_cuboid(vect3f p, vect3f diag);

#endif //GOBJ_CUBOID_H_
