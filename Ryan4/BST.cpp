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
void BST::remove(NodePtr &node, const Element key) {
    if(node == nullptr) {
        return;
    }

    if(key < node->element) {
        remove(node->left, key);
    } else if(key > node->element) {
        remove(node->right, key);
    } else {
        removeNode(node);
    }
}

// Handling node removal once node has been found
void BST::removeNode(NodePtr &node) {
    if(node == nullptr) {
        return;
    }

    if(node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
    } else if(node->left != nullptr && node->right == nullptr) {
        NodePtr temp = node;
        node = node->left;
        delete temp;
    } else if(node->left == nullptr && node->right != nullptr) {
        NodePtr temp = node;
        node = node->right;
        delete temp;
    } else {
        NodePtr temp;

        findMaxNode(temp, node->left);
        
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
void BST::findMaxNode(NodePtr &startingNode, NodePtr &maxNode) {
    maxNode = startingNode;
    NodePtr parentOfMax = nullptr;

    while (maxNode->right != nullptr) {
        parentOfMax = maxNode;
        maxNode = maxNode->right;
    }

    if(parentOfMax != nullptr) {
        parentOfMax->right = maxNode->left;
        maxNode->left = nullptr;
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