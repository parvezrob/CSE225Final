#include "QueueType.h"
#include <iostream>
using namespace std;
template <class ItemType>
QueueType<ItemType>::QueueType()
{
    front = NULL;
    rear = NULL;
}
template <class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
    return (front == NULL);
}
template<class ItemType>
bool QueueType<ItemType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
void QueueType<ItemType>::EnQueue(ItemType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;


        if (front==NULL)
            front = newNode;
        else
            rear->next = newNode;

        rear = newNode;
    }
}
template <class ItemType>
void QueueType<ItemType>::DeQueue(ItemType& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        item = front->info;

        NodeType* tempPtr;
        tempPtr = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete tempPtr;
    }
}
template <class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}
template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    MakeEmpty();
}
