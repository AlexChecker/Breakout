//
// Created by alex Cheker on 21.11.2022.
//

#include "Plane.h"


Plane::Plane(float x, float y, float w, float h) {
    pos_x=x;
    pos_y=y;
    width=w;
    height=h;
    collisionPoints[0] = Point(pos_x-width,pos_y+height);
    collisionPoints[1] = Point(pos_x-width,pos_y-height);
    collisionPoints[2] = Point(pos_x+width,pos_y-height);
    collisionPoints[3] = Point(pos_x+width,pos_y+height);
}
