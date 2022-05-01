#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Point{//клас точка для задання координат вершини та координат центру основи
    double x;
    double y;
    double z;
public:
    Point();
    Point(double ,double ,double );
    void setX(double );
    void setY(double );
    void setZ(double );
    double getX();
    double getY();
    double getZ();
    void outPoint(){cout <<"X = \t"<<x<<"Y = \t"<<y<<"Z = \t"<<z;}//вивести координати точки
};
class Radius{
    double R;
public:
    Radius();
    Radius(double );
    void setR(double );
    double getR();
    void outRadius(){cout <<"Radius = \t"<<R;}
};
