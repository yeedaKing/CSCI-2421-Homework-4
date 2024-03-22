/*********************************************************
* Summary: This file includes the header for the BinarySearchTree class (implemented
* in BinarySearchTree.cpp).
*
* This program defines a binary search tree class that remains height balanced after
* each insertion of a new node. This class requires a vector of ints upon initialization
* (values must be sorted). The BinarySearchTree class provides multiple public functions
* including various traversal methods as well as insertion and searching methods.
* Multiple private/helper functions are also utilized within this class, their
* functionality privmarily dedicated to checking and maintaining the balance of the tree.
* Note that deletion is not supported in this implementation of the binary search tree. 
*
* Author: David Yee
* Created: March 20, 2024
* Summary of Modifications [if applicable]:
*
********************************************************/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

class BinarySearchTree {
public:
    // constructor and destructor
    BinarySearchTree(vector<int>& vals);
    ~BinarySearchTree();

    // methods
    TreeNode* getRoot();
    TreeNode* insertNode(TreeNode* node, int val);
    TreeNode* findNode(int val);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int getHeight(TreeNode* node);

private:
    // helper functions
    TreeNode* createMinHeightBST(const vector<int>& vals);
    TreeNode* leftRotate(TreeNode* x);
    TreeNode* rightRotate(TreeNode* y);
    void updateHeight(TreeNode* node);
    int getBalance(TreeNode* node);
    TreeNode* balance(TreeNode* node, int v);
    void dfs(TreeNode* curr);
    void helper(TreeNode* node);

    TreeNode* root;
};

#endif