#include "TreeNode.h"

TreeNode::TreeNode() {
    val = -1;
    left = nullptr;
    right = nullptr;
    height = 0;
}

TreeNode::TreeNode(int val) {
    this->val = val;
    left = nullptr;
    right = nullptr;
    height = 0;
}

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) {
    this->val = val;
    this->left = left;
    this->right = right;
    
    if (!left && !right) {
        height = 0;

    } else if (!left) {
        height = 1+right->getHeight();

    } else if (!right) {
        height = 1+left->getHeight();

    } else {
        height = 1+max(left->getHeight(), right->getHeight());
    }
}

TreeNode::~TreeNode() {
    left = nullptr;
    right = nullptr;
}

void TreeNode::setVal(int newVal) {
    val = newVal;
}

int TreeNode::getVal() {
    return val;
}

void TreeNode::setLeft(TreeNode* newLeft) {
    left = newLeft;
}

TreeNode* TreeNode::getLeft() {
    return left;
}

void TreeNode::setRight(TreeNode* newRight) {
    right = newRight;
}

TreeNode* TreeNode::getRight() {
    return right;
}

void TreeNode::setHeight(int newHeight) {
    height = newHeight;
}

int TreeNode::getHeight() {
    return height;
}