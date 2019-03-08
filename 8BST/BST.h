/**
*	@file :BinarySearchTree.h (BST)
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for template BinarySearchTree class
*           Models the collection of data, holding data, 
*           in multiple BinaryNodes.
*/
#include "BinaryNode.h"
#include "NotFoundException.h"

#ifndef BST_H
#define BST_H


template <typename ItemType, typename KeyType>
class BST
{
    public:
    //constructor
    BST();
    //copyTree constructor
    BST(const BST<ItemType, KeyType>& tree);
    //destructor
    ~BST();
       
    
    //check if the item has no children
    bool isLeaf(BinaryNode<ItemType>* subtree);
    //use Recursive function to add value in tree
    
    //delete a value from tree
    bool remove(const KeyType& target);

    //get fouctions
    ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);

    //find a keyword in tree
    bool search(const KeyType& aKey) const;
    void Add(const ItemType& newEntry) throw(NotFoundException);

    // inserts it in a leaf at that point
    BinaryNode<ItemType>* RecAdd(BinaryNode<ItemType>* subTreePtr,  BinaryNode<ItemType>* newNodePtr);

    //deep copy the whole tree
    BinaryNode<ItemType>* copy(const BinaryNode<ItemType>* treePtr) const;

     // Recursive traversal methods
     void inorderTraverse(void visit(ItemType&)) const;
     void preorderTraverse(void visit(ItemType&)) const;
     void postorderTraverse(void visit(ItemType&)) const;


    private:

    //create a new node for the parent of the tree
    BinaryNode<ItemType>*  m_root;

    // Recursively deletes all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* subTreePtr);
    
    //remove the target Value from a subtree
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType& target);

    //remove the node which have target value
   BinaryNode<ItemType>* removeNode( BinaryNode<ItemType>* nodePtr);

   //switch node.
   BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& inorderSuccessor);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const;

   //visit methods 
   void inorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void preorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
   void postorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;

};
#include "BST.hpp"
#endif

//change ItemType& to BST<ItemType, KeyType>&