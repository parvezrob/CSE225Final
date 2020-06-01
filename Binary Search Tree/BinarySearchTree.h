#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED
#include "QueueType.h"

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
struct TreeNode
{
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

template <class ItemType>
class TreeType
{
public:
    TreeType();
    ~TreeType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType item);
    void DeleteItem(ItemType item);

    void RetrieveItem(ItemType& item, bool& found);
    void ResetTree(OrderType order);
    void GetNextItem(ItemType& item, OrderType order, bool& finished);
    //void Print();
    
    
    int TotalLeaf(); 
    int heightTree();
private:
    TreeNode<ItemType>* root;
    QueueType<ItemType> preQue;
    QueueType<ItemType> inQue;
    QueueType<ItemType> postQue;
};
#include "BinarySearchTree.tpp"
#endif // BINARYSEARCHTREE_H_INCLUDED
