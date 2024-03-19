#include "TreeNode.h"

TreeNode::TreeNode() {
    val = -1;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int val) {
    this->val = val;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) {
    this->val = val;
    this->left = left;
    this->right = right;
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