// Kevin Mattappally and Davis Fairchild
// LINKEDBINARYTREE
// 3-05-18
// TreeNode.h
// dropoff using kmattappally

//ADT TreeNode for a binary tree: data object a node with 
//                            an item and a pointer to left and right children
// operations: constructors

// Especially designed for the BinaryTree class
#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include "Item.h"
using namespace std;

class TreeNode
{
public:
 
//creates an empty tree node
//post: object is an empty tree node
//usage: TreeNode zags;
TreeNode();

//creates a tree node
//post: object is an tree node with an
// item as well as left and right tree
    // node branches
//usage: TreeNode node = new TreeNode(newItem, theLeft, theRight);
TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);
   
Item item;
TreeNode* leftChild;
TreeNode* rightChild;

};
#endif


