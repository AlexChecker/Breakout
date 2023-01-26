//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_PLANE_H
#define BREAKOUT_PLANE_H

#include "structs.h"
#include "../Shader.h"



class Plane {

    public:
    Color col;
    float pos_x;
    float pos_y;
    float width;
    float height;
    Shader shader=Shader("plane.vert","plane.frag");
    // 0-top left
    // 1-bottom left
    // 2-bottom right
    // 3-top right
    struct Point collisionPoints[4];
    uint VAO;
    uint VBO;
    uint EBO;
    Plane(float x,float y,float w, float h,Color col);
    void draw();

};


#endif //BREAKOUT_PLANE_H
