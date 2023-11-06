#include "BST.h"
#include <iostream>

using namespace std;

void testInsertAndSearch(BST &bst) {
    cout << "Inserting elements 5, 3, 7, 2, 4, 6, 8 into the BST." << endl;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    // Test search function
    cout << "Searching for elements 3 and 10 (10 is not inserted)." << endl;
    NodePtr result;
    
    result = bst.search(3);
    cout << "Search for 3: " << (result != nullptr ? "found" : "not found") << endl;

    result = bst.search(10);
    cout << "Search for 10: " << (result != nullptr ? "found" : "not found") << endl;
}

void testRemove(BST &bst) {
    // Removing leaf node
    cout << "Removing leaf node (2)." << endl;
    bst.remove(2);

    // Removing node with one child
    cout << "Removing node with one child (4)." << endl;
    bst.remove(4);

    // Removing node with two children
    cout << "Removing node with two children (5)." << endl;
    bst.remove(5);

    // Attempt to remove a node that doesn't exist
    cout << "Attempting to remove a node that doesn't exist (10)." << endl;
    bst.remove(10);
}

void testTraversals(const BST &bst) {
    cout << "Preorder traversal: ";
    bst.preorderView();

    cout << "Inorder traversal: ";
    bst.inorderView();

    cout << "Postorder traversal: ";
    bst.postorderView();
}

void testCopyConstructor(BST original) {
    BST copy(original);
    cout << "Testing the copy constructor with an inorder traversal:" << endl;
    copy.inorderView();
}

void testDestructor() {
    BST *bst = new BST();
    bst->insert(10);
    bst->insert(5);
    bst->insert(20);
    cout << "BST created on the heap and populated with 10, 5, 20." << endl;

    cout << "Deleting BST." << endl;
    delete bst;
    cout << "BST deleted." << endl;
}

int main() {
    BST bst;
    testInsertAndSearch(bst);
    testTraversals(bst);
    testRemove(bst);
    testTraversals(bst);
    testCopyConstructor(bst);
    testDestructor();

    return 0;
}