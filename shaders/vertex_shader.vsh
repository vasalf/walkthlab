attribute vec3 Position;

uniform mat4 rotate;
uniform mat4 window;
uniform mat4 camera;

void main()
{
    gl_Position = camera * window * rotate * vec4(Position, 1.0);
}
