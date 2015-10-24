#ifndef VECTOR_MATH_H_
#define VECTOR_MATH_H_

#include <math.h>

#ifndef M_PI
static const float M_PI = 3.14f;
#endif

typedef struct
{
    float x, y, z;
} vect3f;

vect3f make_vect3f(float _x, float _y, float _z);

typedef struct
{
    float m[4][4];
} matrix4fv;

matrix4fv make_zero_matrix4fv();
matrix4fv make_one_matrix4fv();

matrix4fv make_xrotation_matrix4fv(float ang);
matrix4fv make_yrotation_matrix4fv(float ang);
matrix4fv make_zrotation_matrix4fv(float ang);

matrix4fv make_movement_matrix4fv(vect3f v);

matrix4fv matrix4fv_product(matrix4fv a, matrix4fv b);

#endif //VECTOR_MATH_H_
