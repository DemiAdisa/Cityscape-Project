in vec2 v_uv1;
in vec3 normal;


uniform sampler2D tex;
uniform vec3 LightColor;
uniform vec3 LightDir;
uniform vec3 AmbientLight;

out vec4 PixelColor;

void main()
{
    vec3 diffuseLight = LightColor * max(0, dot(normal, LightDir));
    vec3 diffuseMat = texture(tex, v_uv1).rgb;
    PixelColor.rgb = diffuseMat * (AmbientLight + diffuseLight);
    PixelColor.a = 1.0;    
    //PixelColor = texture(tex, v_uv1);
}