/*********************************************************
* Summary: This file includes the implementation for the BinarySearchTree class (defined
* in BinarySearchTree.h).
*
* This program implements a binary search tree class that remains height balanced after
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

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(vector<int>& vals) {
    /*
    ''' AVL TREE METHOD - does not require sorted vector '''
    root = nullptr;
    for (int val: vals) {
        root = insertNode(root, val);
    }
    */

    // create a minimum height BST using the divide and conquer approach
    root = createMinHeightBST(vals);
}

TreeNode* BinarySearchTree::createMinHeightBST(const vector<int>& vals) {
    /**
     * Private helper function for the constructor. Uses a divide and conquer
     * approach to create the tree.
     * 
     *
     * @param vals vector that stores the values for the nodes
     * @return Pointer to a TreeNode (the root of the tree)
     */

    // all values have been used up if vector is empty, so return null
    if (vals.empty()) {
        return nullptr;
    }
    // repeatedly divide vector into two halves; recursively create left and right subtrees
    int mid = vals.size()/2;
    TreeNode* newNode = new TreeNode(vals[mid]);

    vector<int> left(vals.begin(), vals.begin()+mid);
    newNode->setLeft(createMinHeightBST(left));

    vector<int> right(vals.begin()+mid+1, vals.end());
    newNode->setRight(createMinHeightBST(right));

    // set the height for newly created node and return the node
    updateHeight(newNode);
    return newNode;
}

BinarySearchTree::~BinarySearchTree() {
    // call the dfs helper function to delete all nodes within the tree
    dfs(root);
}

void BinarySearchTree::dfs(TreeNode* curr) {
    /**
     * Private helper function for the destructor. Uses DFS to traverse the
     * tree and delete each node.
     *
     * @param curr current node to delete
     * @return void
     */

    // don't do anything if a null value is encountered
    if (!curr) {
        return;
    }
    // delete nodes starting from the leaf nodes (postorder traversal)
    dfs(curr->getLeft());
    dfs(curr->getRight());
    delete curr;
    curr = nullptr;
}

TreeNode* BinarySearchTree::getRoot() {
    return root;
}

TreeNode* BinarySearchTree::insertNode(TreeNode* node, int val) {
    /**
     * Inserts a node into the tree. Finds respective insertion spot
     * via recursion. The private balance function is called after an
     * insertion to ensure that the tree remains height balanced.
     *
     * @param node current node in the tree
     * @param val value of the new node
     * @return A pointer to the root (root may change through rotations)
     */

    // create new node once null is encountered
    if (!node) {
        TreeNode* newNode = new TreeNode(val);
        return newNode;

    } else if (node->getVal() < val) {
        node->setRight(insertNode(node->getRight(), val));

    } else {
        node->setLeft(insertNode(node->getLeft(), val));
    }
    // update the heights for each node if necessary and check for imbalance
    updateHeight(node);
    return balance(node, val);
}

TreeNode* BinarySearchTree::findNode(int val) {
    /**
     * Finds a value within the tree via iteration. Returns nullptr if
     * value is not found, returns a pointer to the respective TreeNode
     * otherwise.
     *
     * @param val value to find
     * @return A pointer to the TreeNode (or null if not found)
     */

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
    /**
     * Prints the tree's values in a preorder traversal. Iteratively
     * traverses the tree using a stack and a pointer pointing to the
     * current node.
     *
     * @return void
     */

    stack<TreeNode*> s;
    TreeNode* current = root;
    while (!s.empty() || current) {
        // keep traversing the left subtree of current until null is encountered
        while (current) {
            // push the current node onto the stack to process its right subtree later
            s.push(current);
            cout << current->getVal() << ' ';
            current = current->getLeft();
        }
        // traverse the right subtree of the node at the top of the stack now
        current = s.top()->getRight();
        s.pop();
    }
    cout << endl;
}

void BinarySearchTree::inOrderTraversal() {
    /**
     * Prints the tree's values in an inorder traversal. Iteratively
     * traverses the tree using a stack and a pointer pointing to the
     * current node.
     *
     * @return void
     */

    stack<TreeNode*> s;
    TreeNode* current = root;
    while (!s.empty() || current) {
        // keep traversing the left subtree of current until null is encountered
        while (current) {
            // push the current node onto the stack to process its right subtree later
            s.push(current);
            current = current->getLeft();
        }
        // process the node at the top of the stack, then explore its right child
        current = s.top();
        cout << current->getVal() << ' ';
        current = current->getRight();
        s.pop();
    }
    cout << endl;
}

void BinarySearchTree::postOrderTraversal() {
    // call the helper function to recursively traverse the tree
    helper(root);
    cout << endl;
}

void BinarySearchTree::helper(TreeNode* node) {
    /**
     * Prints the tree's values in a postorder traversal. Recursively
     * traverses the tree.
     *
     * @param node pointer to the current node
     * @return void
     */

    if (!node) {
        return;
    }
    // first process the left subtree, then right subtree, and finally parent
    helper(node->getLeft());
    helper(node->getRight());
    cout << node->getVal() << ' ';
}

int BinarySearchTree::getHeight(TreeNode* node) {
    /**
     * Returns the height of a given node. Returns -1 if node is null
     *
     * @param node return height for this node
     * @return An integer representing the height of given node
     */

    if (!node) {
        return -1;
    }
    return node->getHeight();
}

void BinarySearchTree::updateHeight(TreeNode* node) {
    /**
     * Private member function that updates the height of a node.
     * Used by the insertion function and the rotation functions.
     *
     * @param node update the height for this node
     * @return void
     */

    node->setHeight(1 + max(getHeight(node->getLeft()), getHeight(node->getRight())));
}

int BinarySearchTree::getBalance(TreeNode* node) {
    /**
     * Private member function that calculates the balance of a
     * given node. Used by the balance function.
     *
     * @param node find the balance for this node
     * @return An integer representing the balance of given node
     */

    if (!node) {
        return 0;
    }
    return getHeight(node->getLeft()) - getHeight(node->getRight());
}

TreeNode* BinarySearchTree::leftRotate(TreeNode* x) {
    /**
     * Private member function that performs a left rotation on a
     * given node. Used by the balance function.
     *
     * @param x node to perform the rotation on
     * @return A pointer to the new parent node
     */

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
    /**
     * Private member function that performs a right rotation on a
     * given node. Used by the balance function.
     *
     * @param y node to perform the rotation on
     * @return A pointer to the new parent node
     */

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
    /**
     * Private member function that checks if tree is imbalanced
     * and performs rotations when necessary. Calls other private
     * functions to perform its tasks.
     *
     * @param node check balance/perform rotation(s) on this node
     * @param v value to compare
     * @return A pointer to the new parent node
     */

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