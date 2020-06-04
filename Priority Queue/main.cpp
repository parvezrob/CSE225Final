#include <iostream>
#include "pqtype.h"
#include "point.h"
int main() {


    int n;
    cin>>n;
    PQType pointPQ(n);
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        point p(x,y);
       
        pointPQ.Enqueue(p);
    }
    
    pointPQ.print();
    
    
    
       }

    return 0;
}
