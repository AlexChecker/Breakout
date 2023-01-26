#version 330 core
layout (location=0) in vec3 pos;

uniform float posp;

void main() {
    gl_Position = vec4(pos.x+posp,pos.y,pos.z,1.0);
}
