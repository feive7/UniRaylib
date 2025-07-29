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
uniform vec3 viewPos;

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

    vec3 lightDot = vec3(0.0);
    vec3 normal = normalize(fragNormal);
    vec3 viewD = normalize(viewPos - fragPosition);
    vec3 specular = vec3(0.0);

    vec4 tint = colDiffuse * fragColor;

    vec3 lighting = vec3(0);
    for (int i = 0; i < 10; i++) {
        vec3 light = vec3(0.0);
        light = normalize(lights[i].position - fragPosition);

        float NdotL = max(dot(fragNormal, light),0.0);
        lightDot += lights[i].color.rgb*NdotL*lights[i].power;

        float specCo = 0.0;
        if (NdotL > 0.0) specCo = pow(max(0.0, dot(viewD, reflect(-(light), normal))), 16.0); // 16 refers to shine
        specular += specCo;
        // Portal light calculation
        //vec3 offset = lightPortals[0].pos2 - lightPortals[0].pos1;
        //lighting += (light.power / Vec3Distance(light.position + offset, fragPosition));
        //lighting += (light.power / Vec3Distance(light.position - offset, fragPosition));
    }
    finalColor = (texelColor*((tint + vec4(specular, 1.0))*vec4(lightDot, 1.0)));
    finalColor += texelColor*(ambientLight/10.0)*tint;

    finalColor = pow(finalColor, vec4(1.0/2.2));
}
