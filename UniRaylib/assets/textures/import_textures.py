import os

textures_header_file = "../../Textures.h"
files = os.listdir("./")

textures = []

for file in files:
    filename = os.path.splitext(file)[0]
    ext = os.path.splitext(file)[1]
    if os.path.isfile(file) and ext == ".png" or ext == ".jpg":
        textures.append([filename,os.path.abspath(file).replace("\\","/")])

with open(textures_header_file,'w') as f:
    for texture in textures:
        f.write("Texture " + texture[0] + ";\n")
    f.write("\nvoid InitTextures() {\n")
    for texture in textures:
        f.write("\t" + texture[0] + " = LoadTexture(\"" + texture[1] + "\");\n")
    f.write("}\n")
    f.write("void UnloadTextures() {\n")
    for texture in textures:
        f.write("\tUnloadTexture(" + texture[0] + ");\n") 
    f.write("}")   