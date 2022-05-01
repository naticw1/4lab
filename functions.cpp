#include "functions.h"
#include "cone.h"
int inputSize(){
    int n;
    cout <<"Enter number of cones : "<<endl;
    cin >>n;
    while (n < 1){
        cout <<"Enter the correct number of cones :"<<endl;
        cin >> n;
    }
    return n;
}
double inputCoo(){
    double c;
    cin >>c;
    /*while (isdigit(c) == 0 ){
        cout <<"Enter the correct  :";
        cin >> c;
    }*/
    while (c < 0 ){
        cout <<"Enter the correct  :";
        cin >> c;
    }
    return c;
}
Cone * input(int size){
    Cone * cones = new Cone[size];
    for (int i = 0; i < size; i++){
        cout <<"Cone "<<i+1<<":"<<endl;
        Point points[2];
        for (int j = 0; j < 2; j ++){
            cout <<"Enter x coordinate : ";
            int x = inputCoo();
            cout <<"Enter y coordinate : ";
            int y = inputCoo();
            cout <<"Enter z coordinate : ";
            int z = inputCoo();
            points[j] = Point(x,y,z);
        }
        cout <<"Enter the radius of the base of the cone :";
        double r = inputCoo();
        cones[i] = Cone(points , r);
    }
    return cones;
}
int getINdex(Cone * cones , int size){
    int index;
    for (int i = 1; i < size; i++){
        if (cones[i].getGenerator() > cones[0].getGenerator()){
            index = i;
        }
    }
    return index;
}
void outAllCones(Cone* cones ,int size){
    cout <<"All cones :"<<endl;
    for (int i = 0; i < size; i++){
        cout <<"Cone "<<i + 1<<":"<<endl;
        cones[i].out();
    }
}
void outMax(Cone* cones , int max){
    cout <<"Max generator have this cone"<<max + 1<<" :"<<endl;
    cones[max].out();
}


