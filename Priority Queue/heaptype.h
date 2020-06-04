#ifndef HEAPTYPE_H_INCLUDED
#define HEAPTYPE_H_INCLUDED
#include "point.h"
using namespace std;

struct HeapType
{
    void ReheapDown(int root, int bottom);
    void ReheapUp(int root, int bottom);

    int* elements;
    //int numElements;
};
#include "heaptype.tpp"
#endif // HEAPTYPE_H_INCLUDED
