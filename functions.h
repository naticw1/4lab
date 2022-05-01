#pragma once
#include <string>
//#include <ctype.h>
#include "cone.h"
using namespace std;
int inputSize();
double inputCoo();
Cone * input(int size);
int getINdex(Cone * cones , int size);
void outAllCones(Cone* cones ,int size);
void outMax(Cone* cones , int max);
