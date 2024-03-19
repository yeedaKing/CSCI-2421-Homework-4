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

    void insertNode(int val);
    TreeNode* findNode(int val);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int findHeight(TreeNode* node);

private:
    void dfs(TreeNode* curr);
    void helper(TreeNode* node);
    TreeNode* root;
};

#endif