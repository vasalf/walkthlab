#include <math.h>

#include <vector_math.h>

inline vect3f make_vect3f(float _x, float _y, float _z)
{
    vect3f v;
    v.x = _x; v.y = _y; v.z = _z;
    return v;
}

matrix4fv make_zero_matrix4fv()
{
    matrix4fv res;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            res.m[i][j] = 0;
    return res;
}

matrix4fv make_one_matrix4fv()
{
    matrix4fv res = make_zero_matrix4fv();
    for (int i = 0; i < 4; i++)
        res.m[i][i] = 1;
    return res;
}

matrix4fv make_xrotation_matrix4fv(float ang)
{
    matrix4fv res = make_one_matrix4fv();
    res.m[1][1] = cosf(ang);
    res.m[1][2] = -sinf(ang);
    res.m[2][1] = sinf(ang);
    res.m[2][2] = cosf(ang);
    return res;
}

matrix4fv make_yrotation_matrix4fv(float ang)
{
    matrix4fv res = make_one_matrix4fv();
    res.m[0][0] = cosf(ang);
    res.m[0][2] = -sinf(ang);
    res.m[2][0] = sinf(ang);
    res.m[2][2] = cosf(ang);
    return res;
}

matrix4fv make_zrotation_matrix4fv(float ang)
{
    matrix4fv res = make_one_matrix4fv();
    res.m[0][0] = cosf(ang);
    res.m[0][1] = -sinf(ang);
    res.m[1][0] = sinf(ang);
    res.m[1][1] = cosf(ang);
    return res;
}


