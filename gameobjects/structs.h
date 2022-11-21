//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_STRUCTS_H
#define BREAKOUT_STRUCTS_H
#include <iostream>
#include <vector>


struct Point
{
public:
    float x,y;
    Point(float x,float y)
    {
        this->x=x;
        this->y=y;
    }
    Point()
    {

    }

    ///
    /// \param first First point
    /// \param second Second point
    /// \param mode 1 - is lower,2- is upper,3 -intersect on right,4 - intersrct on left
    /// \return is intersecting
    bool isIntersects(Point first,Point second,int mode = 1)
    {
        //std::cout<<"First point height "<<first.y<<std::endl;
        if(x>first.x&&x<second.x)
        {
            //if(y>first.y) return true;
            switch (mode) {
                case 1:
                    if(y<first.y){
                        std::cout<<"True!!!"<<y<<"|"<<first.y<<std::endl;
                        return true;
                    }
                    break;
            }
        }
        return false;
    }
};
#endif //BREAKOUT_STRUCTS_H
