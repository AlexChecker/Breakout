//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_PLATFORM_H
#define BREAKOUT_PLATFORM_H
#include "../Shader.h"
#include "structs.h"
#include <vector>

#define P_WIDTH .3
#define P_HEIGHT .05


class Platform {
public:
    Platform(std::string vshader,std::string fshader);
    Platform();
    void draw();
    void moveLeft();
    void moveRight();
    struct Point collisionPoints[2];
private:
    uint VAO_PLATFORM;
    uint VBO_PLATFORM;
    uint EBO_PLATFORM;
    Shader platform_shader;
    float x_pos;
    float platform_vertices[12]=
            {
                    -P_WIDTH,-1+P_HEIGHT,0.0, // top left
                    -P_WIDTH,-1.0,0.0,       // bottom left
                    P_WIDTH,-1+P_HEIGHT,0.0,  // top right
                    P_WIDTH,-1.0,0.0       // bottom right
            };
    uint platform_index[6]=
            {
                    0,1,2,
                    1,2,3
            };


};


#endif //BREAKOUT_PLATFORM_H
