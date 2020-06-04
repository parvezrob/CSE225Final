#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED


#include "pqtype.h"

class point{

public :
	int x;
   	int y;    

    point();
    point(int x,int y);
    int getX();
    int getY();
    int compare(point, point);
};


#include "point.tpp"
#endif // POINT_H_INCLUDED
