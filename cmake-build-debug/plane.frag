#version 330 core

uniform vec3 col;
out vec4 fragColor;
void main() {
    fragColor=vec4(col.r,col.g,col.b,1.0);
}