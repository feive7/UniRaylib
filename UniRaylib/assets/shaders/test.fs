#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragPosition;
in vec3 fragNormal;

struct LightPortal {
    vec3 pos1;
    vec3 pos2;
};
struct Light {
    vec3 position;
    float power;
    vec3 color;
};

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform Light lights[10];
uniform LightPortal lightPortals[10];

// Output fragment color
out vec4 finalColor;

// NOTE: Add your custom variables here

float Vec3DistanceSqr(vec3 a, vec3 b) {
    float xx = b.x - a.x;
    float yy = b.y - a.y;
    float zz = b.z - a.z;
    return xx*xx+yy*yy+zz*zz;
}
float Vec3Distance(vec3 a, vec3 b) {
    return sqrt(Vec3DistanceSqr(a,b));
}
void main() {
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec3 lighting = vec3(0);
   
    Light light = lights[0];
    vec3 lightDir = normalize(light.position - fragPosition); // Correct light direction

    vec3 color = abs(fragNormal);

    finalColor = vec4(color,1.0);
}
