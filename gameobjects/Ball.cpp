//
// Created by alex Cheker on 21.11.2022.
//

#include "Ball.h"



Ball::Ball(std::string vshader, std::string fshader)  {
    //this->platform=platform;
    ball_shader =Shader(vshader.c_str(),fshader.c_str());
    x_pos =.0f;
    y_pos = -.95f;

    glGenVertexArrays(1,&VAO_BALL);
    glBindVertexArray(VAO_BALL);
    glGenBuffers(1,&VBO_BALL);
    glBindBuffer(GL_ARRAY_BUFFER,VBO_BALL);
    //std::cout<<"BALL VERTICES: "<<vertices_ball[0]<<std::endl;
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices_ball),vertices_ball,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1,&EBO_BALL);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO_BALL);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices_ball),indices_ball,GL_STATIC_DRAW);
    std::cout<<"VAO BALL: "<<VAO_BALL<<std::endl;
    glBindVertexArray(0);
    collisionPoints[0]=Point(x_pos,y_pos-BALL_H);
}

void Ball::draw()
{
    glBindVertexArray(VAO_BALL);

    ball_shader.use();
    ball_shader.setVec2f("pos_rel",x_pos,y_pos);

    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glBindVertexArray(0);

}

void Ball::update(/*std::vector<Plane>& planes*/Platform platform) {

    collisionPoints[0]=Point(x_pos,y_pos-BALL_H);
    if(isAlive) {
        if(y_pos<-1.0f)
            isAlive=false;
        if (collisionPoints[0].isIntersects(platform.collisionPoints[0], platform.collisionPoints[1])) {
            velocity_multiplyer_y = 1;
        }
        if (y_pos > .9) velocity_multiplyer_y = -1;
        if (x_pos > .9)
            velocity_multiplyer_x = -1;
        if (x_pos < -0.9)
            velocity_multiplyer_x = 1;


        x_pos += .02f * velocity_multiplyer_x;
        y_pos+= .02f*velocity_multiplyer_y;
        std::cout << y_pos << std::endl;
    }
}




