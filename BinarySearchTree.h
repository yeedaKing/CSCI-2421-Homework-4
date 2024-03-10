#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "TreeNode.h"
#include <vector>

using std::vector;

class BinarySearchTree {
public:
    BinarySearchTree(vector<int> vals);
    ~BinarySearchTree();

    void insertNode(int val);
    TreeNode* findNode(int val);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int findHeight();

private:
    void dfs(TreeNode* curr);
    TreeNode* root;
};

#endif