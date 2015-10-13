attribute vec3 Position;

uniform mat4 rotate;
uniform mat4 window;

void main()
{
    gl_Position = window * rotate * vec4(Position, 1.0);
}
