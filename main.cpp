#include "functions.h"
int main(){
    int size = inputSize();
    Cone * cones = input(size);
    int index = getINdex(cones,size);
    outAllCones(cones,size);
    outMax(cones,index);

}
