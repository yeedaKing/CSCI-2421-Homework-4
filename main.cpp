#include "TreeNode.h"
#include "BinarySearchTree.h"

int main() {
    vector<int> vals;
    int input;
    cout << "Enter values for tree, enter -1 to stop" << endl;
    cout << "---------------------------------------" << endl;
    cin >> input;
    while (input != -1) {
        vals.push_back(input);
        cin >> input;
    }
    BinarySearchTree tree = BinarySearchTree(vals);

    cout << "\npreorder traversal: ";
    tree.preOrderTraversal();
    cout << "inorder traversal: ";
    tree.inOrderTraversal();
    cout << "postorder traversal: ";
    tree.postOrderTraversal();
}