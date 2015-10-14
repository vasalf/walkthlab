#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gl_render.h>
#include <vector_math.h>

#include <gl_objects/gl_object.h>

static float cur_rotate = 0;

oneway_gl_object_ptr_list to_draw;

void render(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    matrix4fv rotation = matrix4fv_product(matrix4fv_product(make_xrotation_matrix4fv(cur_rotate), make_yrotation_matrix4fv(cur_rotate)), make_zrotation_matrix4fv(cur_rotate));
    matrix4fv window_size_matrix = make_one_matrix4fv();
    window_size_matrix.m[1][1] = (float)window_size.width / (float)window_size.height;

    glUniformMatrix4fv(gl_uniforms.rotate_location, 1, GL_TRUE, &rotation.m[0][0]);
    glUniformMatrix4fv(gl_uniforms.window_location, 1, GL_TRUE, &window_size_matrix.m[0][0]);
    cur_rotate += 0.0003;
    
    for (oneway_gl_object_ptr_list_iter* it = to_draw.begin; it != NULL; it = it->next)
    {
        draw_gl_object(*(it->val));
    }

    glfwSwapBuffers(window);
}
