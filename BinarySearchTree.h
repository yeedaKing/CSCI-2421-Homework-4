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
    BinarySearchTree(vector<int> vals);
    ~BinarySearchTree();

    TreeNode* insertNode(TreeNode* node, int val);
    TreeNode* findNode(int val);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int getHeight(TreeNode* node);

private:
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