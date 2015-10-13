#ifndef GL_COMMON_H_
#define GL_COMMON_H_

void init_gl_libs();
void gl_main_loop();
void init_shaders(const char* vsh_filename, const char* fsh_filename);
void terminate_gl_libs();

#endif //GL_COMMON_H_
