#version 330 core

out vec4 fragColor;

void main() {
    fragColor=vec4(1.0,1.0,1.0,1.0);
    //if(sqrt(pow(distance(gl_FragCoord.x,coll_pos_top.x),2)+pow(distance(gl_FragCoord.y,coll_pos_top.y),2))>.9) fragColor=vec4(1.0,.0,.0,1.0);
}
