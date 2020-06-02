#include "StackType.h"
#include <iostream>

using namespace std;

int main()

{
 StackType <int> st;
 
 st.Push(10);
 st.Push(9);
 st.Push(8);
 st.Push(7);
 st.Push(6);
 st.Push(5);
 st.Push(4);
 st.Push(3);
 st.Push(2);
 st.Push(1);

 st.Reverse();
 
 while(!st.IsEmpty())
 {
   cout<<st.Top()<<endl;
   st.Pop();
 }
 

}
