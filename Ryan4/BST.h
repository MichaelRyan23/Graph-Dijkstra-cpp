#pragma once
typedef int Element;
struct Node;
typedef Node * NodePtr;
struct Node {
    Element element;
    NodePtr left, right;
};

class BST {
    
    public:

        BST();
        BST(const BST &old);
        ~BST();
        
        void insert(const Element);
        void remove(const Element);
        NodePtr search(const Element) const;
        void preorderView() const;
        void inorderView() const;
        void postorderView() const;

    private:

        NodePtr root;
        void copy(const NodePtr);
        void destroy(NodePtr &);
        void removeNode(NodePtr &);
        void findMaxNode(NodePtr &, NodePtr &);
        void insert(NodePtr &, const Element);
        void remove(NodePtr &, const Element);
        NodePtr search(const NodePtr, const Element) const;
        void preorderView(const NodePtr) const;
        void inorderView(const NodePtr) const;
        void postorderView(const NodePtr) const;

};