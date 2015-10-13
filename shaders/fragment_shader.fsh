uniform vec3 color;

void main()
{
    gl_FragColor.rgba = vec4(color, 1.0);
}
