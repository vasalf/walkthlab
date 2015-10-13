#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gl_render.h>
#include <vector_math.h>

static GLuint VBO;

void create_vbo()
{
    vect3f vertices[3] = {make_vect3f(-0.5f, -0.5f, 0.0f),
        make_vect3f(0.5f, -0.5f, 0.0f),
        make_vect3f(0.0f, 0.5f, 0.0f)
    };
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

static float cur_rotate = 0;

void render(GLFWwindow* window)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    matrix4fv rotation = make_zrotation_matrix4fv(cur_rotate);

    glUniformMatrix4fv(gl_uniforms.rotate_location, 1, GL_TRUE, &rotation.m[0][0]);
    cur_rotate += 0.0001;

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glfwSwapBuffers(window);
}
