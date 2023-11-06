/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSc 300
*** ASSIGNMENT :    4
*** DUE DATE :      11/8/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : The ADT being implemented is a BST. It stores elements
*** in a sorted manner so searching, inserting, and deletion goes smoothly.
*** Each node contains an element value, along with pointers to the left
*** and right child nodes. Traversal methods are also used throughout 
*** implementation.
********************************************************************/
#include "BST.h"
#include <iostream>
using namespace std;

/********************************************************************
*** FUNCTION Constructor
*********************************************************************
*** DESCRIPTION : Initializes a new object of a BST ADT, setting the root
*** node to nullptr
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
BST::BST() : root(nullptr) {}

/********************************************************************
*** FUNCTION Copy constructor
*********************************************************************
*** DESCRIPTION : Creates a new object of a BST, but copies data into it
*** from an existing BST with the help of the copy function.
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
BST::BST(const BST &old): root(nullptr) {
    if(old.root) {
        copy(old.root);
    }
}

// Copy helper function
void BST::copy(const NodePtr oldNode) {
    if(oldNode) {
        insert(oldNode->element);
        copy(oldNode->left);
        copy(oldNode->right);
    }
}

/********************************************************************
*** FUNCTION Destructor
*********************************************************************
*** DESCRIPTION : Deallocates nodes in the BST, trying to account for memory
*** leaks. Destructor is called whne BST object goes out of scope or is deleted.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
BST::~BST() {
    destroy(root);
}

/********************************************************************
*** FUNCTION Insert
*********************************************************************
*** DESCRIPTION : Inserts an element into the BST accordingly in order.
*** If element already exists, duplication is ignored.
*** INPUT ARGS : key
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
void BST::insert(const Element key) {
    insert(root, key);
}

void BST::insert(NodePtr &node, const Element key) {
    if(!node) {
        node = new (std::nothrow) Node{key, nullptr, nullptr};

        if(node == nullptr) {
            cout << "Memory Allocation error!!!";
        }
    } else if(key < node->element) {
        insert(node->left, key);
    } else if(key > node->element) {
        insert(node->right, key);
    }
    // ignoring a duplication
}

/********************************************************************
*** FUNCTION Search
*********************************************************************
*** DESCRIPTION : Searches for an element in the BST and returns pointer 
*** that points to the node containing the key element. If not found, nullptr
*** INPUT ARGS : key
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : NodePtr
********************************************************************/
NodePtr BST::search(const Element key) const {
    return search(root, key);
}

NodePtr BST::search(const NodePtr node, const Element key) const {
    if(node == nullptr) {
        cout << "Node not found!" << endl;
        return nullptr;
    } else if(key == node->element) {
        return node;
    } else if(key < node->element) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

/********************************************************************
*** FUNCTION Remove
*********************************************************************
*** DESCRIPTION : Removes an element from the BST if it exists. Adjusts 
*** tree to maintain BST properties after removal.
*** INPUT ARGS : key
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
void BST::remove(const Element key) {
    remove(root, key);
}

// private recursive remove
void BST::remove(NodePtr &rootNode, const Element key) {

    if(rootNode == nullptr) {
        return;
    }

    if(key < rootNode->element) {
        remove(rootNode->left, key);
    } else if(key > rootNode->element) {
        remove(rootNode->right, key);
    } else {
        removeNode(rootNode);
    }
}

// Handling node removal once node has been found
void BST::removeNode(NodePtr &node) {

    if(node == nullptr) {
        return;
    }

    // no children
    if(node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    }
    // left child only
    else if(node->left != nullptr && node->right == nullptr) {
        NodePtr temp = node;
        node = node->left;
        delete temp;
    } 
    // right child only
    else if(node->left == nullptr && node->right != nullptr) {
        NodePtr temp = node;
        node = node->right;
        delete temp;
    } 
    // two children
    else {
        NodePtr temp = nullptr;

        findMaxNode(node->left, temp);

        node->element = temp->element;

        remove(node->left, temp->element);
    }
}

/********************************************************************
*** FUNCTION Pre-order view
*********************************************************************
*** DESCRIPTION : Prints elements of BST in preorder traversal. V L R order.
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
void BST::preorderView() const {
    cout << "BEGIN -> ";
    preorderView(root);
    cout << "END" << endl;
}

void BST::preorderView(const NodePtr node) const {
    if (node) {
        cout << node->element << " -> ";
        preorderView(node->left);
        preorderView(node->right);
    }
}

/********************************************************************
*** FUNCTION In-order view
*********************************************************************
*** DESCRIPTION : Prints elements of BST in 'in-order' traversal. L V R
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
void BST::inorderView() const {
    cout << "BEGIN -> ";
    inorderView(root);
    cout << "END" << endl;
}

void BST::inorderView(const NodePtr node) const {
    if (node) {
        inorderView(node->left);
        cout << node->element << " -> ";
        inorderView(node->right);
    }
}

/********************************************************************
*** FUNCTION Post-order view
*********************************************************************
*** DESCRIPTION : Prints elements of BST in postorder traversal. L R V
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS : 
*** RETURN : 
********************************************************************/
void BST::postorderView() const {
    cout << "BEGIN -> ";
    postorderView(root);
    cout << "END" << endl;
}

void BST::postorderView(const NodePtr node) const {
    if (node) {
        postorderView(node->left);
        postorderView(node->right);
        cout << node->element << " -> ";
    }
}

// recursive destroy
void BST::destroy(NodePtr &node) {
    
    if(node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
        node = nullptr;
    }
}

// find maximum node on left subtree side
void BST::findMaxNode(NodePtr &maxNode, NodePtr &temp) {

    if(maxNode->right == nullptr) {
        temp = maxNode;
        return;
    } else {
        findMaxNode(maxNode->right, temp);
    }
}
