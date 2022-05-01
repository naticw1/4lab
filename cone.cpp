#include "cone.h"
Cone::Cone(){};
Cone::Cone(Point Or, Point A, Radius r) {
    this->Or = Point(Or.getX() ,Or.getY(), Or.getZ());
    this->A = Point(A.getX(),A.getY(),A.getZ());
    this->r = Radius(r.getR());
    this->l = gtgenerator();


}
Cone::Cone(Point points[2],Radius r) {
    this->Or = Point(points[0].getX(),points[0].getY(),points[0].getZ());
    this->A = Point(points[1].getX(),points[1].getY(),points[1].getZ());
    this->r = Radius(r.getR());
    this->l = gtgenerator();


}
double Cone::gtgenerator() {
    double gen = pow((Or.getX()-A.getX()),2) + pow((Or.getY()-A.getY()),2)+ pow(Or.getZ() - A.getZ(),2)+ pow((r.getR()),2);
    return sqrt(gen);
}
double Cone::getGenerator() {
    return l;
}
void Cone::out(){
    cout << "Point O :";
    Or.outPoint();
    cout << "Point A :";
    A.outPoint();
    cout <<"Radius :";
    r.outRadius();
    cout <<"Generator :"<<getGenerator()<<endl;


}
