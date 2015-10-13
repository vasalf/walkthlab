#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <gl_common.h>
#include <gl_render.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Error in glfw: %d\n%s\n", error, description);
}

static GLFWwindow* window;

void init_gl_libs()
{
    assert(glfwInit());
    window = glfwCreateWindow(640, 480, "platypus", NULL, NULL);
    glfwSetErrorCallback(glfw_error_callback);
    window_size.height = 480;
    window_size.width = 640;
    assert(window);
    glfwMakeContextCurrent(window);

    assert(glewInit() == GLEW_OK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void gl_main_loop()
{
    while (!glfwWindowShouldClose(window))
    {
        render(window);
    }
}

void terminate_gl_libs()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

static const char* read_file(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* res = malloc(fsize + 1);
    assert(fread(res, fsize, 1, f));
    fclose(f);

    res[fsize] = '\0';
    return res;
}

static void add_shader(GLuint program, const char* text, GLenum type)
{
    GLuint sobj = glCreateShader(type);
    const GLchar* p[1];
    p[0] = text;
    GLint lens[1];
    lens[0] = strlen(text);
    glShaderSource(sobj, 1, p, lens);
    glCompileShader(sobj);
    GLint success;
    glGetShaderiv(sobj, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLchar log[1024];
        glGetShaderInfoLog(sobj, 1024, NULL, log);
        fprintf(stderr, "Shader compilation error:\n%s", log);
    }
    assert(success);
    glAttachShader(program, sobj);
}

void init_shaders(const char* vsh_filename, const char* fsh_filename)
{
    GLuint sprog = glCreateProgram();
    assert(sprog);
    add_shader(sprog, read_file(vsh_filename), GL_VERTEX_SHADER);
    add_shader(sprog, read_file(fsh_filename), GL_FRAGMENT_SHADER);

    GLint success = 0;

    glLinkProgram(sprog);
    glGetProgramiv(sprog, GL_LINK_STATUS, &success);
    assert(success);

    glValidateProgram(sprog);
    glGetProgramiv(sprog, GL_VALIDATE_STATUS, &success);
    assert(success);
    glUseProgram(sprog);
    
    gl_uniforms.rotate_location = glGetUniformLocation(sprog, "rotate");
    assert(gl_uniforms.rotate_location != (GLuint)(~0));
    gl_uniforms.color_location = glGetUniformLocation(sprog, "color");
    assert(gl_uniforms.color_location != (GLuint)(~0));
    gl_uniforms.window_location = glGetUniformLocation(sprog, "window");
    assert(gl_uniforms.window_location != (GLuint)(~0));

}
