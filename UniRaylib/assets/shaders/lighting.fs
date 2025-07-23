#version 330

// Input vertex attributes (from vertex shader)
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragPosition;

struct LightPortal {
    vec3 pos1;
    vec3 pos2;
};
struct Light {
    vec3 position;
    float power;
};

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;
uniform Light lights[10];
uniform LightPortal lightPortals[10];

// Output fragment color
out vec4 finalColor;

// NOTE: Add your custom variables here
float Vec3Distance(vec3 a, vec3 b) {
    float xx = b.x - a.x;
    float yy = b.y - a.y;
    float zz = b.z - a.z;
    return sqrt(xx*xx+yy*yy+zz*zz);
}
void main() {
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec3 lighting = vec3(0);
    for (int i = 0; i < 10; i++) {
        Light light = lights[i];
        lighting += (light.power / Vec3Distance(light.position, fragPosition));

        // Portal light calculation
        vec3 offset = lightPortals[0].pos2 - lightPortals[0].pos1;
        lighting += (light.power / Vec3Distance(light.position + offset, fragPosition));
        lighting += (light.power / Vec3Distance(light.position - offset, fragPosition));
    }
    finalColor = texelColor*colDiffuse*fragColor;
    finalColor.rgb *= lighting;
}
