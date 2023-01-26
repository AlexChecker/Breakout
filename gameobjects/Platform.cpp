//
// Created by alex Cheker on 21.11.2022.
//

#include "Platform.h"

Platform::Platform(std::string vshader, std::string fshader) {
    platform_shader = Shader(vshader.c_str(),fshader.c_str());
    glGenVertexArrays(1,&VAO_PLATFORM);
    glBindVertexArray(VAO_PLATFORM);

    glGenBuffers(1,&VBO_PLATFORM);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_PLATFORM);
    glBufferData(GL_ARRAY_BUFFER,sizeof(platform_vertices),platform_vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1,&EBO_PLATFORM);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO_PLATFORM);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof (platform_index),platform_index,GL_STATIC_DRAW);
    glBindVertexArray(0);
    collisionPoints[0]=Point(x_pos-P_WIDTH,-1+P_HEIGHT);
    collisionPoints[1]=Point(x_pos+P_WIDTH,-1+P_HEIGHT);

}

void Platform::draw() {
    platform_shader.use();
    platform_shader.setFloat("posp",x_pos);
    glBindVertexArray(VAO_PLATFORM);

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);
}

void Platform::moveLeft() {
    if(x_pos >-0.6&&!(x_pos>-.6&&x_pos<-.5))
        x_pos-=.1;

    collisionPoints[0]=Point(x_pos-P_WIDTH,-1+P_HEIGHT);
    collisionPoints[1]=Point(x_pos+P_WIDTH,-1+P_HEIGHT);
}

void Platform::moveRight() {
    if(x_pos<0.6&&!(x_pos<.6&&x_pos>.5))
        x_pos+=.1;
    collisionPoints[0]=Point(x_pos-P_WIDTH,-1+P_HEIGHT);
    collisionPoints[1]=Point(x_pos+P_WIDTH,-1+P_HEIGHT);
}

Platform::Platform() {

}
