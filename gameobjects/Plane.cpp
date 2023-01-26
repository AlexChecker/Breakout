//
// Created by alex Cheker on 21.11.2022.
//

#include "Plane.h"


Plane::Plane(float x, float y, float w, float h,Color col) {
    this->col = col;
    pos_x=x;
    pos_y=y;
    width=w;
    height=h;
    collisionPoints[0] = Point(pos_x-width,pos_y+height); // top left
    collisionPoints[1] = Point(pos_x-width,pos_y-height); // bottom left
    collisionPoints[2] = Point(pos_x+width,pos_y-height); // bottom right
    collisionPoints[3] = Point(pos_x+width,pos_y+height); // top right
    float vertices[]=
            {pos_x-width,pos_y+height,.0,//top left
             pos_x-width,pos_y-height,.0,//bottom left
             pos_x+width,pos_y+height,.0,//top right
             pos_x+width,pos_y-height,.0// bottom right
             };
    uint indices[]=
            {
            0,1,2,
            1,2,3
            };
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1,&EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof (indices),indices,GL_STATIC_DRAW);
    glBindVertexArray(0);
}

void Plane::draw() {
    glBindVertexArray(VAO);
    shader.use();
    shader.setVec3f("col",col.r,col.g,col.b);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);

}
