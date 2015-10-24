#ifndef GL_PERSPECTIVE_H_
#define GL_PERSPECTIVE_H_

#include <vector_math.h>

typedef struct
{
    vect3f pos;
    vect3f straight;
    vect3f up;
} camera_t;

extern camera_t camera;

void move_camera(vect3f dv);
void relocate_camera(vect3f new_pos);
void horisontaly_rotate_camera(float angle);
void verticaly_rotate_camera(float angle);

matrix4fv get_camera_matrix4fv();

#endif //GL_PERSPECTIVE_H_
