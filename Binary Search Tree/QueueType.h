#ifndef QueueTYPE_H_INCLUDED
#define QueueTYPE_H_INCLUDED
class FullQueue
{};
class EmptyQueue
{};
template <class ItemType>
class QueueType
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };
public:
    QueueType();
    ~QueueType();
    void MakeEmpty();
    void EnQueue(ItemType);
    void DeQueue(ItemType&);
    bool IsEmpty();
    bool IsFull();
private:
    NodeType *front, *rear;
};
#include "QueueType.tpp"
#endif // QueueTYPE_H_INCLUDED
