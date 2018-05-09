// Kevin Mattappally and Davis Fairchild
// LINKEDBINARYTREE
// 3-05-18
// TreeNode.cpp
// dropoff using kmattappally

//ADT TreeNode for a binary tree: data object a node with
//                            an item and a pointer to left and right children
//                             left and right children are also TreeNodes
// operations: constructors

// Especially designed for the BinaryTree class

#include "TreeNode.h"
//creates an empty tree node
//post: object is an empty tree node
//usage: TreeNode zags;
TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}

//creates a tree node
//post: object is an tree node with an
// item as well as left and right tree
// node branches
//usage: TreeNode node = new TreeNode(newItem, theLeft, theRight);
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
