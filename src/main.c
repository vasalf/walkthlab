#include <vector_math.h>
#include <gl_common.h>
#include <gl_render.h>
#include <gl_objects/cuboid.h>
#include <oneway_list.h>

int main()
{
    init_gl_libs();
    init_shaders("shaders/vertex_shader.vsh", "shaders/fragment_shader.fsh");
    gl_object lcube = make_cuboid(make_vect3f(-0.5, -0.5, 0), make_vect3f(0.5, 0.5, 0.5));
    lcube.colors[0] = make_vect3f(1, 0, 0);
    lcube.colors[1] = make_vect3f(0, 1, 0);
    lcube.colors[2] = make_vect3f(0, 0, 1);
    lcube.colors[3] = make_vect3f(0, 1, 1);
    lcube.colors[4] = make_vect3f(1, 0, 1);
    lcube.colors[5] = make_vect3f(1, 1, 0);
    oneway_gl_object_ptr_list_push(&to_draw, &lcube);
    gl_object rcube = make_cuboid(make_vect3f(0, -0.5, -0.5), make_vect3f(0.5, 0.5, 0.5));
    rcube.colors[0] = make_vect3f(1, 0, 0);
    rcube.colors[1] = make_vect3f(0, 1, 0);
    rcube.colors[2] = make_vect3f(0, 0, 1);
    rcube.colors[3] = make_vect3f(0, 1, 1);
    rcube.colors[4] = make_vect3f(1, 0, 1);
    rcube.colors[5] = make_vect3f(1, 1, 0);
    oneway_gl_object_ptr_list_push(&to_draw, &rcube);
    gl_main_loop();
    terminate_gl_libs();
    return 0;
}
