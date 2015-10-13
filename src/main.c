#include <gl_common.h>
#include <gl_render.h>

int main()
{
    init_gl_libs();
    init_shaders("shaders/vertex_shader.vsh", "shaders/fragment_shader.fsh");
    create_vbo();
    gl_main_loop();
    terminate_gl_libs();
    return 0;
}
