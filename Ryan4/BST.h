/********************************************************************
*** NAME :          Michael Ryan
*** CLASS :         CSc 300
*** ASSIGNMENT :    4
*** DUE DATE :      11/8/2023
*** INSTRUCTOR :    GAMRADT 
*********************************************************************
*** DESCRIPTION : BST is an ADT that manages integer elements in a sorted
*** order for operations like insert, remove, search, etc. The data has
*** a descending tree-like order, in which every single node has at least
*** 2 child nodes. 
********************************************************************/
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

/********************************************************************
*** FUNCTION Constructor
*********************************************************************
*** DESCRIPTION : Creates an empty binary search tree
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        BST();

/********************************************************************
*** FUNCTION Copy constructor
*********************************************************************
*** DESCRIPTION : Creates a new BST originating from an existing BST using
*** the copy feature.
*** INPUT ARGS : old
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        BST(const BST &old);

/********************************************************************
*** FUNCTION Destructor
*********************************************************************
*** DESCRIPTION : Destroys the BST, releasing allocated resources
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        ~BST();
        
/********************************************************************
*** FUNCTION Insert
*********************************************************************
*** DESCRIPTION : Inserts an element into the BST while maintaining the
*** overall structure of the tree
*** INPUT ARGS : Element
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        void insert(const Element);

/********************************************************************
*** FUNCTION Remove
*********************************************************************
*** DESCRIPTION : Removes an element from the BST while maintinging the
*** overall structure of the tree
*** INPUT ARGS : Element
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        void remove(const Element);

/********************************************************************
*** FUNCTION Search
*********************************************************************
*** DESCRIPTION : Searches for an element in the BST
*** INPUT ARGS : Element
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN : NodePtr - pointer to node containing searched element
********************************************************************/
        NodePtr search(const Element) const;

/********************************************************************
*** FUNCTION Pre-order view
*********************************************************************
*** DESCRIPTION : Displays the elements of the BST using preorder traversal
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        void preorderView() const;

/********************************************************************
*** FUNCTION In-order view
*********************************************************************
*** DESCRIPTION : Displays the elemetns of the BST using inorder traversal
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
        void inorderView() const;

/********************************************************************
*** FUNCTION Post-order view
*********************************************************************
*** DESCRIPTION : Displays the elements of the BST using postorder traversal
*** INPUT ARGS : 
*** OUTPUT ARGS : 
*** IN/OUT ARGS :
*** RETURN :
********************************************************************/
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