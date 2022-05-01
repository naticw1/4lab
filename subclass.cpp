#include "subclass.h"
Point::Point() {};
Point::Point(double x , double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
void Point::setX(double x) {
    this->x = x;
}
void Point::setY(double y) {
    this->y = y;
}
void Point::setZ(double z) {
    this->z = z;
}
double Point::getX() {
    return this->x;
}
double Point::getY() {
    return this-> y;
}
double Point::getZ() {
    return this->z ;
}
Radius::Radius() {};
Radius::Radius(double R) {
    this->R = R;
}
void Radius::setR(double R) {
    this->R = R;
}
double Radius::getR() {
    return this->R;
}

