#ifndef TREENODE_H
#define TREENODE_H

#include <algorithm>
using std::max;

class TreeNode {
public:
    TreeNode();
    TreeNode(int val);
    TreeNode(int val, TreeNode* left, TreeNode* right);
    ~TreeNode();

    void setVal(int newVal);
    int getVal();

    void setLeft(TreeNode* newLeft);
    TreeNode* getLeft();

    void setRight(TreeNode* newRight);
    TreeNode* getRight();

    void setHeight(int newHeight);
    int getHeight();

private:
    int val;
    TreeNode* left;
    TreeNode* right;
    int height;
};

#endif