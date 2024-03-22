/*********************************************************
* Summary: This file includes the header for the TreeNode class (implemented in
* TreeNode.cpp).
*
* This program defines a TreeNode class for the BinarySearchTree class. This TreeNode
* class offers the typical funcitonality of a BST node: value, left pointer, and right
* pointer setters/getters. Each TreeNode object will also contain a height member
* variable to aid in the self-balancing property of this implementation of BST.
*
* Author: David Yee
* Created: March 20, 2024
* Summary of Modifications [if applicable]:
*
********************************************************/

#ifndef TREENODE_H
#define TREENODE_H

#include <algorithm>
using std::max;

class TreeNode {
public:
    // constructors and destructor
    TreeNode();
    TreeNode(int val);
    TreeNode(int val, TreeNode* left, TreeNode* right);
    ~TreeNode();

    // setters and getters
    void setVal(int newVal);
    int getVal();

    void setLeft(TreeNode* newLeft);
    TreeNode* getLeft();

    void setRight(TreeNode* newRight);
    TreeNode* getRight();

    void setHeight(int newHeight);
    int getHeight();

private:
    // declare variables
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
};

#endif