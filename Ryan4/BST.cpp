#include "BST.h"
#include <iostream>
using namespace std;

// constructor
BST::BST() : root(nullptr) {}

// copy constructor
BST::BST(const BST &old): root(nullptr) {
    if(old.root) {
        copy(old.root);
    }
}

// Destructor
BST::~BST() {
    destroy(root);
}

// insert
void BST::insert(const Element key) {
    insert(root, key);
}

void BST::insert(NodePtr &node, const Element key) {
    if(!node) {
        node = new (std::nothrow) Node{key, nullptr, nullptr};
    } else if(key < node->element) {
        insert(node->left, key);
    } else if(key > node->element) {
        insert(node->right, key);
    }
    // ignoring a duplication
}

// search
NodePtr BST::search(const Element key) const {
    return search(root, key);
}

NodePtr BST::search(const NodePtr node, const Element key) const {
    if(node == nullptr) {
        cout << "Element not found!" << endl;
        return nullptr;
    } else if(key == node->element) {
        return node;
    } else if(key < node->element) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

// public remove
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
        
        if(temp == nullptr) {
            cout << "Max node in left subtree not found!" << endl;
            return;
        }

        node->element = temp->element;

        remove(node->left, temp->element);
    }
}

// preorder view
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

// inorder view
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

// postorder view
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

// Copy helper function
void BST::copy(const NodePtr oldNode) {
    if(oldNode) {
        insert(oldNode->element);
        copy(oldNode->left);
        copy(oldNode->right);
    }
}