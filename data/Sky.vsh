in vec4 a_position;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 world;


void main()
{
    gl_Position = projection * view * world * a_position;
    
    
}