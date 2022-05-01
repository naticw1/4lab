#pragma once
#include "subclass.h"
class Cone{
    Point Or , A;//Or - центр основи ; A - вершина
    Radius r;// r - raдіус основи
    double l ;//l - твірна
    double gtgenerator();

public:
    Cone();
    Cone(Point Or , Point A , Radius r);
    Cone(Point points[2], Radius r);
    double getGenerator();
    void out();

};
