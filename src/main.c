#include <vector_math.h>
#include <gl_common.h>
#include <gl_render.h>
#include <gl_objects/cuboid.h>
#include <oneway_list.h>

int main()
{
    init_gl_libs();
    init_shaders("shaders/vertex_shader.vsh", "shaders/fragment_shader.fsh");
    cube = make_cuboid(make_vect3f(-0.5, -0.5, -0.75), make_vect3f(1.0, 1.0, 1.0));
    cube.colors[0] = make_vect3f(1, 0, 0);
    cube.colors[1] = make_vect3f(0, 1, 0);
    cube.colors[2] = make_vect3f(0, 0, 1);
    cube.colors[3] = make_vect3f(0, 1, 1);
    cube.colors[4] = make_vect3f(1, 0, 1);
    cube.colors[5] = make_vect3f(1, 1, 0);
    gl_main_loop();
    terminate_gl_libs();
    return 0;
}
