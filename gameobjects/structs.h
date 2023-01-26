//
// Created by alex Cheker on 21.11.2022.
//

#ifndef BREAKOUT_STRUCTS_H
#define BREAKOUT_STRUCTS_H
#include <iostream>
#include <vector>



struct Color
{
public:
    float r,g,b;
    Color(float red,float green,float blue)
    {
        r=red;
        g=green;
        b=blue;
    }
    Color()
    {

    }
};


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
    bool isIntersects(Point first,Point second,float height,float width ,const int mode = 1)
    {
        //std::cout<<"First point height "<<first.y<<std::endl;
        if(mode==1||mode==2) {
            if (x > first.x && x < second.x) {
                //if(y>first.y) return true;
                switch (mode) {
                    case 1:
                        if (y < first.y&&y>first.y-height/2) {
                            std::cout << "True bottom " << y << "|" << first.y <<"|"<<first.y-height<< std::endl;
                            return true;
                        }
                        break;
                    case 2:
                        //std::cout<<"Plane collision debug! "<<y<<"|"<<first.y<<std::endl;
                        if (y > first.y&&y<first.y+height/2) {
                            //std::cout << "True top! " << y << "|" << first.y <<"|"<<first.y+height<< std::endl;
                            return true;}
                        break;
                }
            }
        }
        //else
        //{
        //
        //    if(y>first.y&&y<second.y)
        //    {
        //        switch(mode)
        //        {
        //            case 3:
        //                if(x>first.x) return true;
        //                break;
        //            case 4:
        //                if(x<first.x) return true;
        //                break;
        //        }
        //    }
        //}
        return false;
    }
};
#endif //BREAKOUT_STRUCTS_H
