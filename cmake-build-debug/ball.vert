#version 330 core
layout(location=0)in vec3 pos;

uniform vec2 pos_rel;

void main() {
    gl_Position=vec4(pos.x+pos_rel.x,pos.y+pos_rel.y,pos.z,1.0);
}