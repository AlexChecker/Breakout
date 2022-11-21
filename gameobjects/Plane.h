//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_PLANE_H
#define BREAKOUT_PLANE_H

#include "structs.h"


class Plane {

    public:
    float pos_x;
    float pos_y;
    float width;
    float height;
    struct Point collisionPoints[4];
    Plane(float x,float y,float w, float h);

};


#endif //BREAKOUT_PLANE_H
