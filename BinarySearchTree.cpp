#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(vector<int> vals) {

}

BinarySearchTree::~BinarySearchTree() {
    dfs(root);
}

void BinarySearchTree::dfs(TreeNode* curr) {
    if (!curr) {
        return;
    }
    dfs(curr->getLeft());
    dfs(curr->getRight());
    delete curr;
    curr = nullptr;
}

void BinarySearchTree::insertNode(int val) {

}

TreeNode* BinarySearchTree::findNode(int val) {
    TreeNode* curr = root;
    while (curr) {
        if (curr->getVal() == val) {
            return curr;

        } else if (curr->getVal() < val) {
            curr = curr->getRight();

        } else {
            curr = curr->getLeft();
        }
    }
    return nullptr;
}

void BinarySearchTree::preOrderTraversal() {
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (!s.empty() || current) {
        while (current) {
            s.push(current);
            cout << current->getVal() << ' ';
            current = current->getLeft();
        }
        current = s.top()->getRight();
        s.pop();
    }
    cout << endl;
}

void BinarySearchTree::inOrderTraversal() {
    stack<TreeNode*> s;
    TreeNode* current = root;
    while (!s.empty() || current) {
        while (current) {
            s.push(current);
            current = current->getLeft();
        }
        current = s.top();
        cout << current->getVal() << ' ';
        current = current->getRight();
        s.pop();
    }
    cout << endl;
}

void BinarySearchTree::postOrderTraversal() {
    helper(root);
    cout << endl;
}
void BinarySearchTree::helper(TreeNode* node) {
    if (!node) {
        return;
    }
    helper(node->getLeft());
    helper(node->getRight());
    cout << node->getVal() << ' ';
}

int BinarySearchTree::findHeight(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1+max(findHeight(node->getLeft()), findHeight(node->getRight()));
}