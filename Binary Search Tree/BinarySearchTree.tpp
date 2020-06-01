#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
template <class ItemType>
TreeType<ItemType>::TreeType()
{
    root = NULL;
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
{
    if (tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
        tree = NULL;
    }
}

template <class ItemType>
TreeType<ItemType>::~TreeType()
{
    Destroy(root);
}

template <class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
    Destroy(root);
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
    return root == NULL;
}

template <class ItemType>
bool TreeType<ItemType>::IsFull()
{
    TreeNode<ItemType>* location;
    try {
        location = new TreeNode<ItemType>;
        delete location;
        return false;
    } catch(bad_alloc& exception) {
        return true;
    }
}

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
{
    if (tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

template <class ItemType>
int TreeType<ItemType>::LengthIs()
{
    return CountNodes(root);
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found)
{
    if (tree == NULL)
        found = false;
    else if (item < tree->info)
        Retrieve(tree->left, item, found);
    else if (item > tree->info)
        Retrieve(tree->right, item, found);
    else {
        item = tree->info;
        found = true;
    }
}

template <class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    Retrieve(root, item, found);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
{
    // reference of a treenode pointer variable
    if (tree == NULL) {
        tree = new TreeNode<ItemType>;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if (item < tree->info)
        Insert(tree->left, item);
    else
        Insert(tree->right, item);
}

template <class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
    Insert(root, item);
}

template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
{
    while (tree->right != NULL)
        tree = tree->right;
    data = tree->info;
}

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
{

    TreeNode<ItemType>* tempPtr;
    tempPtr = tree;
    if (tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if (tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        ItemType data;
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);
    }
}

template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
{
    if (item < tree->info)
        Delete(tree->left, item);
    else if (item > tree->info)
        Delete(tree->right, item);
    else
        DeleteNode(tree);
}

template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
{
    Delete(root, item);
}

template <class ItemType>
void PreOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& Que)
{
    if (tree != NULL) {
        Que.EnQueue(tree->info);
        PreOrder(tree->left, Que);
        PreOrder(tree->right, Que);
    }
}

template <class ItemType>
void InOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& Que)
{
    if (tree != NULL) {
        InOrder(tree->left, Que);
        Que.EnQueue(tree->info);
        InOrder(tree->right, Que);
    }
}

template <class ItemType>
void PostOrder(TreeNode<ItemType>* tree, QueueType<ItemType>& Que)
{
    if (tree != NULL) {
        PostOrder(tree->left, Que);
        PostOrder(tree->right, Que);
        Que.EnQueue(tree->info);
    }
}
template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
{
    switch (order) {
    case PRE_ORDER:
        preQue.MakeEmpty();
        PreOrder(root, preQue);
        break;
    case IN_ORDER:
        inQue.MakeEmpty();
        InOrder(root, inQue);
        break;
    case POST_ORDER:
        postQue.MakeEmpty();
        PostOrder(root, postQue);
        break;
    }
}
template <class ItemType>
void TreeType<ItemType>::GetNextItem(ItemType& item, OrderType order, bool& finished)
{
    finished = false;
    switch (order) {
    case PRE_ORDER:
        preQue.DeQueue(item);
        if(preQue.IsEmpty())
            finished = true;
        break;
    case IN_ORDER:
        inQue.DeQueue(item);
        if(inQue.IsEmpty())
            finished = true;
        break;
    case POST_ORDER:
        postQue.DeQueue(item);
        if(postQue.IsEmpty())
            finished = true;
        break;
    }
}
template <class ItemType>
int TreeType<ItemType>::TotalLeaf()
{
    return (Leaf(root));
}

template <class ItemType>
int Leaf(TreeNode<ItemType>* tree)
{
    if(tree==NULL)
        return 0;
    else if(tree->left==NULL && tree->right==NULL)
        return 1;
    else
        return (Leaf(tree->right)+Leaf(tree->left));

}

template <class ItemType>
int TreeType<ItemType>::heightTree()
{
 return height(root);

}
template <class ItemType>
int height(TreeNode<ItemType>* tree)
{
  if(tree==NULL)
  return 0;

  else {

  int R_height= height(tree->right);
  int L_height= height(tree->left);

  if(R_height>L_height)
   return (R_height+1);
   else
   return (L_height+1);


  }

}

