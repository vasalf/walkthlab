#include <math.h>

#include <gl_perspective.h>

camera_t camera;

void move_camera(vect3f dv)
{
    camera.pos.x += dv.x;
    camera.pos.y += dv.y;
    camera.pos.z += dv.z;
}

void relocate_camera(vect3f new_pos)
{
    camera.pos = new_pos;
}

static inline vect3f cross_product(vect3f u, vect3f v)
{
    return make_vect3f(u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

static inline float dot_product(vect3f u, vect3f v)
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

void horisontaly_rotate_camera(float ang)
{
    vect3f x = cross_product(camera.straight, camera.up);
    vect3f a = make_vect3f(x.x, camera.up.x, camera.straight.x);
    vect3f b = make_vect3f(x.y, camera.up.y, camera.straight.y);
    vect3f c = make_vect3f(x.z, camera.up.z, camera.straight.z);
    vect3f u = make_vect3f(cosf(M_PI / 2 + ang), 0, cosf(ang));
    camera.straight = make_vect3f(dot_product(a, u), dot_product(b, u), dot_product(c, u));
}

matrix4fv get_camera_matrix4fv()
{
    vect3f right = cross_product(camera.straight, camera.up);
    matrix4fv res = make_one_matrix4fv();
    res.m[0][0] = right.x; res.m[0][1] = camera.up.x; res.m[0][2] = camera.straight.x;
    res.m[1][0] = right.y; res.m[1][1] = camera.up.y; res.m[1][2] = camera.straight.y;
    res.m[2][0] = right.z; res.m[2][1] = camera.up.z; res.m[2][2] = camera.straight.z;
    res = matrix4fv_product(make_movement_matrix4fv(make_vect3f(0, 0, -1)), res); 
    res = matrix4fv_product(res, make_movement_matrix4fv(make_vect3f(0, 0, 1))); 
    return res;
}
