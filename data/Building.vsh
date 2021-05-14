in vec4 a_position;
in vec2 a_uv1;
in vec3 a_normal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 world;


out vec3 normal;
out vec2 v_uv1;

void main()
{
    gl_Position = projection * view * world * a_position;
    v_uv1 = a_uv1;
    normal = a_normal;
}
