//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H
#include "Plane.h"
#include "Platform.h"
#include "structs.h"
#include "../Shader.h"
#include <vector>
#include <random>
#include <exception>
#define BALL_W .05f
#define BALL_H .05f




class Ball {
public:
    uint VAO_BALL;
    uint VBO_BALL;
    uint EBO_BALL;
    Shader ball_shader;
    float x_pos;
    float y_pos;
    float velocity_multiplyer_x =-1;
    int velocity_multiplyer_y=1;
    // 0-bottom
    // 1-top
    // 2-left
    // 3-right
    struct Point collisionPoints[4];
    bool isAlive=true;
    float vertices_ball[12]=
    {
        -BALL_W,BALL_H,.0,   //left up
                -BALL_W,-BALL_H,.0,   //left bottom
                BALL_W,BALL_H,.0,    //right up
                BALL_W,-BALL_H,.0    //right bottom
    };
    uint indices_ball[6]=
            {
                    0,1,2,
                    1,2,3
            };

    Ball(std::string vshader,std::string fshader);
    void update( std::vector<Plane>& planes,Platform platform);
    void draw();
};


#endif //BREAKOUT_BALL_H
