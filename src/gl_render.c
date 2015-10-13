#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gl_render.h>
#include <vector_math.h>

static GLuint VBOs[6];
static vect3f colors[6];

void create_vbo()
{
    vect3f vertices[24] = {make_vect3f(-0.5f, -0.5f, -0.5f),
        make_vect3f(0.5f, -0.5f, -0.5f),
        make_vect3f(0.5f, 0.5f, -0.5f),
        make_vect3f(-0.5f, 0.5f, -0.5f),
        
        make_vect3f(-0.5f, -0.5f, 0.5f),
        make_vect3f(0.5f, -0.5f, 0.5f),
        make_vect3f(0.5f, 0.5f, 0.5f),
        make_vect3f(-0.5f, 0.5f, 0.5f),

        make_vect3f(0.5f, -0.5f, -0.5f),
        make_vect3f(0.5f, 0.5f, -0.5f),
        make_vect3f(0.5f, 0.5f, 0.5f),
        make_vect3f(0.5f, -0.5f, 0.5f),

        make_vect3f(-0.5f, -0.5f, -0.5f),
        make_vect3f(-0.5f, 0.5f, -0.5f),
        make_vect3f(-0.5f, 0.5f, 0.5f),
        make_vect3f(-0.5f, -0.5f, 0.5f),

        make_vect3f(-0.5f, -0.5f, -0.5f),
        make_vect3f(0.5f, -0.5f, -0.5f),
        make_vect3f(0.5f, -0.5f, 0.5f),
        make_vect3f(-0.5f, -0.5f, 0.5f),

        make_vect3f(-0.5f, 0.5f, -0.5f),
        make_vect3f(0.5f, 0.5f, -0.5f),
        make_vect3f(0.5f, 0.5f, 0.5f),
        make_vect3f(-0.5f, 0.5f, 0.5f)
    };
    colors[0] = make_vect3f(1, 0, 0);
    colors[1] = make_vect3f(0, 1, 0);
    colors[2] = make_vect3f(0, 0, 1);
    colors[3] = make_vect3f(0, 1, 1);
    colors[4] = make_vect3f(1, 0, 1);
    colors[5] = make_vect3f(1, 1, 0);
    glGenBuffers(6, VBOs);
    for (int i = 0; i < 6; i++)
    {
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vect3f) * 4, vertices + 4 * i, GL_STATIC_DRAW);
    }
}

static float cur_rotate = 0;

void render(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    matrix4fv rotation = make_yrotation_matrix4fv(cur_rotate);
    matrix4fv window_size_matrix = make_one_matrix4fv();
    window_size_matrix.m[1][1] = (float)window_size.width / (float)window_size.height;

    glUniformMatrix4fv(gl_uniforms.rotate_location, 1, GL_TRUE, &rotation.m[0][0]);
    glUniformMatrix4fv(gl_uniforms.window_location, 1, GL_TRUE, &window_size_matrix.m[0][0]);
    cur_rotate += 0.0003;

    for (int i = 0; i < 6; i++)
    {
        glUniform3f(gl_uniforms.color_location, colors[i].x, colors[i].y, colors[i].z);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[i]);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glDrawArrays(GL_QUADS, 0, 4);

        glDisableVertexAttribArray(0);
    }
    glfwSwapBuffers(window);
}
