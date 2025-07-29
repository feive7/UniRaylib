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
uniform float ambientLight;
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
    for (int i = 0; i < 10; i++) {
        Light light = lights[i];
        
        vec3 lightDir = normalize(light.position - fragPosition); // Correct light direction

        float distance = Vec3DistanceSqr(light.position,fragPosition);
        float attenuation = max(0.0,light.power / distance);

        float NdotL = max(dot(fragNormal, lightDir),0.0);
        
        lighting += light.color * attenuation * NdotL;

        // Portal light calculation
        //vec3 offset = lightPortals[0].pos2 - lightPortals[0].pos1;
        //lighting += (light.power / Vec3Distance(light.position + offset, fragPosition));
        //lighting += (light.power / Vec3Distance(light.position - offset, fragPosition));
    }
    lighting = max(vec3(ambientLight,ambientLight,ambientLight),lighting);
    finalColor = texelColor*colDiffuse*fragColor;
    finalColor.rgb *= lighting;
}