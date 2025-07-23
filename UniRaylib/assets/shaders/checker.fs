#version 330
#define MAX_LIGHTS 100
#define TEXTURESCALE 4
#define IGNORE_Y_DISTANCE true
// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;
bool disable = false;

struct Light {
    vec3 position;
    vec3 color;
    float power;
};

// Input uniform values
uniform sampler2D texture0;
uniform vec3 size;
uniform Light lights[10];
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;
float snap(float a, float b) {
    return floor(a * b) / b;
}
vec2 snap(vec2 a, float b) {
    return vec2(snap(a.x,b),snap(a.y,b));
}
vec3 snap(vec3 a, float b) {
    return vec3(snap(a.x,b),snap(a.y,b),snap(a.z,b));
}
void main() {
    vec3 fp = fragPosition * size;
    vec2 coord;
    vec3 texelColor;
    if (abs(fragNormal.x) > 0.5) {
        texelColor = texture(texture0, fp.zy / TEXTURESCALE).rgb;
    }
    if (abs(fragNormal.y) > 0.5) {
        texelColor = texture(texture0, fp.xz / TEXTURESCALE).rgb;
    }
    if (abs(fragNormal).z > 0.5) {
        texelColor = texture(texture0, fp.xy / TEXTURESCALE).rgb;
    }
    vec3 lighting = vec3(0);
    float shade = 0;
    for (int i = 0; i < MAX_LIGHTS; i++) {
        Light light = lights[i];
        if (IGNORE_Y_DISTANCE) {
            light.position.y = 0;
            fp.y = 0;
        }
        lighting += light.color * (light.power / distance(light.position, fp));
    }
    lighting = min(vec3(.5,.5,.5),lighting);
    //shade = min(1,shade);
    if(disable) {
        finalColor = vec4(texelColor,1);
    }
    else {
        finalColor = vec4(texelColor * lighting,1);
    }
}