#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED
#include <iostream>
using namespace std;
const int MAX_ITEMS = 10;

class FullStack
// Exception class thrown
// by Push when stack is full.
{

    void printExceptionMsg(){
        cout<<"Stack is full"<<endl;
    }

};

class EmptyStack
// Exception class thrown
// by Pop and Top when stack is empty.
{
private:
    string reason;

public:

    EmptyStack(string reason){
        this->reason = reason;
    }
    //int x = 5;
    void printExceptionMsg(){
        cout<<"Empty stack exception thrown from "<<reason<<endl;
    }

};


template <class ItemType>
class StackType
{
public:
    StackType();
    bool IsFull();
    bool IsEmpty();
    void Push(ItemType);
    void Pop();
    ItemType Top();
    void Reverse();
private:
    int top;
    ItemType items[MAX_ITEMS];
};
#include "StackType.tpp"
#endif // STACKTYPE_H_INCLUDED

