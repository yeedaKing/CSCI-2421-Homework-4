/*******************************************************
Name      :  David Yee
Class     :  CSCI 2421 Section 001
PA#       :  Homework 4 - Minimum Height BST
Due Date  :  3/25/2024
*******************************************************/

#include "TreeNode.h"
#include "BinarySearchTree.h"

int main() {
    // vector to store values from user input
    vector<int> vals;
    int input;
    cout << "Enter values for tree (enter -1 to stop)" << endl;
    cout << "---------------------------------------" << endl;
    cin >> input;
    while (input != -1) {
        vals.push_back(input);
        cin >> input;
    }
    // ensure values are sorted before creating the tree (see BinarySearchTree
    // class for details)
    sort(vals.begin(), vals.end());
    BinarySearchTree tree = BinarySearchTree(vals);

    cout << "\npreorder traversal: ";
    tree.preOrderTraversal();
    cout << "inorder traversal: ";
    tree.inOrderTraversal();
    cout << "postorder traversal: ";
    tree.postOrderTraversal();

    cout << "tree height: " << tree.getHeight(tree.getRoot()) << endl;

    int val;
    cout << "Enter value to find in the tree (enter -1 to quit): ";
    cin >> val;
    while (val != -1) {
        TreeNode* node = tree.findNode(val);
        if (node) {
            cout << "Found" << endl;

        } else {
            cout << "Not found" << endl;
        }
        cin >> val;
    }
    cout << endl;
}