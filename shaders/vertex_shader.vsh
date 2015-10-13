attribute vec3 Position;

uniform mat4 rotate;

void main()
{
    gl_Position = rotate * vec4(Position, 1.0);
}
