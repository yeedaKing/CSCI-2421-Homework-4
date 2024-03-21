#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(vector<int> vals) {
    root = nullptr;
    for (int val: vals) {
        root = insertNode(root, val);
    }
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

TreeNode* BinarySearchTree::insertNode(TreeNode* node, int val) {
    if (!node) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;

    } else if (node->getVal() < val) {
        node->setRight(insertNode(node->getRight(), val));

    } else {
        node->setLeft(insertNode(node->getLeft(), val));
    }
    updateHeight(node);
    return balance(node, val);
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

int BinarySearchTree::getHeight(TreeNode* node) {
    if (!node) return -1;
    return node->getHeight();
}

void BinarySearchTree::updateHeight(TreeNode* node) {
    node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight())));
}

int BinarySearchTree::getBalance(TreeNode* node) {
    if (!node) return 0;
    return getHeight(node->getLeft()) - getHeight(node->getRight());
}

TreeNode* BinarySearchTree::leftRotate(TreeNode* x) {
    TreeNode* y = x->getRight();
    TreeNode* T2 = y->getLeft();

    // Perform rotation
    y->setLeft(x);
    x->setRight(T2);

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode* BinarySearchTree::rightRotate(TreeNode* y) {
    TreeNode* x = y->getLeft();
    TreeNode* T2 = x->getRight();

    // Perform rotation
    x->setRight(y);
    y->setLeft(T2);

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode* BinarySearchTree::balance(TreeNode* node, int v) {
    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && v < node->getLeft()->getVal())
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && v > node->getRight()->getVal())
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && v > node->getLeft()->getVal()) {
        node->setLeft(leftRotate(node->getLeft()));
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && v < node->getRight()->getVal()) {
        node->setRight(rightRotate(node->getRight()));
        return leftRotate(node);
    }

    return node;
}