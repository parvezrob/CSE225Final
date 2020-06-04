#include "point.h"
#include <iostream>
#include <math.h>
using namespace std;


point::point(){}

point::point(int x, int y)
{  
  	x=x;
  	y=y;
}

int point::getX()
{
    return x;
}

int point::getY()
{
    return y;
}
  int point::compare(point a, point b)
{

    int aDis = sqrt((a.getX()*a.getX())+(a.getY()*a.getY()));
    int bDis = sqrt((b.getX()*b.getX())+(b.getY()*b.getY()));


    return aDis < bDis ;
}
