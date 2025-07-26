#define LETTER_BOUNDRY_SIZE     0.25f
#define TEXT_MAX_LAYERS         32
#define LETTER_BOUNDRY_COLOR    VIOLET
class TransformableVector3 {
public:
    Vector3 value;

    // Internal function stored to transform the vector
    std::function<void(Vector3&)> transformFunction;

    TransformableVector3(Vector3 initial = { 0, 0, 0 }) {
        value = initial;
    }

    // Set the transformation logic
    void SetTransformFunction(std::function<void(Vector3&)> func) {
        transformFunction = func;
    }

    // Apply the internal transformation function
    void ApplyTransform() {
        if (transformFunction) {
            transformFunction(value);
        }
    }
};

bool SHOW_LETTER_BOUNDRY = false;
bool SHOW_TEXT_BOUNDRY = false;
float LineDistance(Vector2 p, Vector2 start, Vector2 end) {
	Vector2 ab = Vector2Subtract(end, start);
	Vector2 ap = Vector2Subtract(p, start);
	float ab_len2 = Vector2LengthSqr(ab);

	if (ab_len2 == 0.0f) return Vector2Distance(p, start); // a == b

	float t = Vector2DotProduct(ap, ab) / ab_len2;
	t = fmaxf(0.0f, fminf(1.0f, t)); // Clamp to segment

	Vector2 projection = Vector2Add(start, Vector2Scale(ab, t));
	return Vector2Distance(p, projection);
}
bool CheckCollisionPointQuad(Vector2 p, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
	return CheckCollisionPointTriangle(p, a, b, c) || CheckCollisionPointTriangle(p, a, c, d);
}
bool CheckCollisionCircleQuad(Vector2 circleCenter, float radius, Vector2 a, Vector2 b, Vector2 c, Vector2 d) {
	// Check if circle center is inside the quad
	if (CheckCollisionPointQuad(Vector2Add(circleCenter, { 0.001f,0.001f }), a, b, c, d)) {
		return true; // Circle center is inside the quad
	}
	// Check distance from circle center to each edge of the quad
	float dist1 = LineDistance(circleCenter, a, b);
	float dist2 = LineDistance(circleCenter, b, c);
	float dist3 = LineDistance(circleCenter, c, d);
	float dist4 = LineDistance(circleCenter, d, a);
	if (dist1 < radius || dist2 < radius || dist3 < radius || dist4 < radius) {
		return true; // Circle collides with at least one edge of the quad
	}
	return false; // No collision detected
}
void E() {
	printf("Trigger\n");
}
void printV(Vector3 v) {
	printf("%f %f %f\n", v.x, v.y, v.z);
}
void toggle(bool& boolean) {
	boolean = !boolean;
}
static void DrawTextCodepoint3D(Font font, int codepoint, Vector3 position, float fontSize, bool backface, Color tint, float angle)
{
    // Character index position in sprite font
    // NOTE: In case a codepoint is not available in the font, index returned points to '?'
    int index = GetGlyphIndex(font, codepoint);
    float scale = fontSize / (float)font.baseSize;

    // Character destination rectangle on screen
    // NOTE: We consider charsPadding on drawing
    position.x += (float)(font.glyphs[index].offsetX - font.glyphPadding) * scale;
    position.z += (float)(font.glyphs[index].offsetY - font.glyphPadding) * scale;

    // Character source rectangle from font texture atlas
    // NOTE: We consider chars padding when drawing, it could be required for outline/glow shader effects
    Rectangle srcRec = { font.recs[index].x - (float)font.glyphPadding, font.recs[index].y - (float)font.glyphPadding,
                         font.recs[index].width + 2.0f * font.glyphPadding, font.recs[index].height + 2.0f * font.glyphPadding };

    float width = (float)(font.recs[index].width + 2.0f * font.glyphPadding) * scale;
    float height = (float)(font.recs[index].height + 2.0f * font.glyphPadding) * scale;

    if (font.texture.id > 0)
    {
        const float x = 0.0f;
        const float y = 0.0f;
        const float z = 0.0f;

        // normalized texture coordinates of the glyph inside the font texture (0.0f -> 1.0f)
        const float tx = srcRec.x / font.texture.width;
        const float ty = srcRec.y / font.texture.height;
        const float tw = (srcRec.x + srcRec.width) / font.texture.width;
        const float th = (srcRec.y + srcRec.height) / font.texture.height;

        if (SHOW_LETTER_BOUNDRY) DrawCubeWiresV({ position.x + width / 2, position.y, position.z + height / 2 }, { width, LETTER_BOUNDRY_SIZE, height }, LETTER_BOUNDRY_COLOR);

        rlCheckRenderBatchLimit(4 + 4 * backface);
        rlSetTexture(font.texture.id);

        rlPushMatrix();
        rlTranslatef(position.x, position.y - 0.15f, position.z - sin(angle * DEG2RAD) * width);
        rlRotatef(-angle, 0.0f, 1.0f, 0.0f);

        rlBegin(RL_QUADS);
        rlColor4ub(tint.r, tint.g, tint.b, tint.a);

        // Front Face
        rlNormal3f(0.0f, 1.0f, 0.0f);                                   // Normal Pointing Up
        rlTexCoord2f(tx, ty); rlVertex3f(x, y + height, z);              // Top Left Of The Texture and Quad
        rlTexCoord2f(tx, th); rlVertex3f(x, y, z);     // Bottom Left Of The Texture and Quad
        rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z);     // Bottom Right Of The Texture and Quad
        rlTexCoord2f(tw, ty); rlVertex3f(x + width, y + height, z);              // Top Right Of The Texture and Quad

        if (backface)
        {
            // Back Face
            rlNormal3f(0.0f, -1.0f, 0.0f);                              // Normal Pointing Down
            rlTexCoord2f(tx, ty); rlVertex3f(x, y + height, z);          // Top Right Of The Texture and Quad
            rlTexCoord2f(tw, ty); rlVertex3f(x + width, y + height, z);          // Top Left Of The Texture and Quad
            rlTexCoord2f(tw, th); rlVertex3f(x + width, y, z); // Bottom Left Of The Texture and Quad
            rlTexCoord2f(tx, th); rlVertex3f(x, y, z); // Bottom Right Of The Texture and Quad
        }
        rlEnd();
        rlPopMatrix();

        rlSetTexture(0);
    }
}
static void DrawText3DR(Font font, const char* text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint, float angle)
{
    int length = TextLength(text);
    float scale = fontSize / (float)font.baseSize;
    // Convert text to array of codepoints so we can iterate backwards
    int codepoints[512] = { 0 }; // Assuming max 512 characters
    int codepointCount = 0;

    for (int i = 0; i < length;) {
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[i], &codepointByteCount);
        if (codepoint == 0x3f) codepointByteCount = 1;
        codepoints[codepointCount++] = codepoint;
        i += codepointByteCount;
    }

    float textOffsetX = 0.0f;
    float textOffsetY = 0.0f;

    for (int i = codepointCount - 1; i >= 0; i--) {
        int codepoint = codepoints[i];
        int index = GetGlyphIndex(font, codepoint);

        if (codepoint == '\n') {
            textOffsetY += fontSize + lineSpacing;
            textOffsetX = 0.0f;
            continue;
        }

        float advance = (font.glyphs[index].advanceX != 0) ?
            font.glyphs[index].advanceX * scale : font.recs[index].width * scale;

        // Pre-offset to right-align glyphs
        textOffsetX += advance + fontSpacing;

        // Rotate offset
        float rad = angle * DEG2RAD;
        float rotatedX = cos(rad) * textOffsetX;
        float rotatedZ = sin(rad) * textOffsetX;

        Vector3 charPos = {
            position.x - rotatedX,             // subtract to mirror
            position.y - textOffsetY,
            position.z - rotatedZ
        };

        if ((codepoint != ' ') && (codepoint != '\t')) {
            DrawTextCodepoint3D(font, codepoint, charPos, fontSize, backface, tint, angle + 180);
        }
    }
}
static void DrawText3D(Font font, const char* text, Vector3 position, float fontSize, float fontSpacing, float lineSpacing, bool backface, Color tint, float angle)
{
    int length = TextLength(text);
    float textOffsetY = 0.0f;
    float textOffsetX = 0.0f;
    float scale = fontSize / (float)font.baseSize;

    for (int i = 0; i < length;) {
        int codepointByteCount = 0;
        int codepoint = GetCodepoint(&text[length-i-1], &codepointByteCount);
        int index = GetGlyphIndex(font, codepoint);

        if (codepoint == 0x3f) codepointByteCount = 1;

        if (codepoint == '\n') {
            textOffsetY += fontSize + lineSpacing;
            textOffsetX = 0.0f;
        }
        else {
            // Calculate character position in local space
            float offsetX = textOffsetX;
            float offsetZ = 0.0f;

            // Rotate the offset vector around Y-axis (angle in degrees)
            float rad = angle * DEG2RAD;
            float rotatedX = cos(rad) * offsetX - sin(rad) * offsetZ;
            float rotatedZ = sin(rad) * offsetX + cos(rad) * offsetZ;

            Vector3 charPos = {
                position.x + rotatedX,
                position.y - textOffsetY,
                position.z + rotatedZ
            };

            if ((codepoint != ' ') && (codepoint != '\t')) {
                DrawTextCodepoint3D(font, codepoint, charPos, fontSize, backface, tint, angle + 180);
            }

            float advance = (font.glyphs[index].advanceX != 0) ?
                font.glyphs[index].advanceX * scale : font.recs[index].width * scale;

            textOffsetX += advance + fontSpacing;
        }

        i += codepointByteCount;
    }
}
float RandomFloat(float min, float max, float step = 0.1f) {
    return GetRandomValue(min / step, max / step) * step;
}
Color RandomColor(bool random_alpha = false) {
    unsigned char alpha = 255;
    if (random_alpha)
        alpha = (unsigned char)GetRandomValue(0, 255);
    return { (unsigned char)GetRandomValue(0,255), (unsigned char)GetRandomValue(0,255), (unsigned char)GetRandomValue(0,255), alpha };
}
void printC(Color c) {
    printf("%u %u %u (%u)\n", c.r, c.g, c.b, c.a);
}