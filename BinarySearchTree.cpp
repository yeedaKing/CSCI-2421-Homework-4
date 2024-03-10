#include BinarySearchTree.h

BinarySearchTree::BinarySearchTree(vector<int> vals) {

}

~BinarySearchTree::BinarySearchTree() {
    dfs();
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
    
}

void BinarySearchTree::inOrderTraversal() {

}

void BinarySearchTree::postOrderTraversal() {

}

int BinarySearchTree::findHeight() {
    TreeNode* curr = root;
    
}