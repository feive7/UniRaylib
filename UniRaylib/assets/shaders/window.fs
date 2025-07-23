#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragPosition;
in vec2 test;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

// NOTE: Add your custom variables here

void main()
{
    // Texel color fetching from texture sampler
    vec2 fragCoord = gl_FragCoord.xy / vec2(800.0,450.0);
    vec4 texelColor = texture(texture0, fragCoord);
    //vec4 texelColor = vec4(fragCoord,1.0,1.0);
    finalColor = texelColor*fragColor;
}
