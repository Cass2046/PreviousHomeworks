/**
*	@file :BinarySearchTree.hpp (BST)
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for template BinarySearchTree class
*/

#include "BST.h"
#include "BinaryNode.h"
#include "NotFoundException.h"
#include "Pokemon.h"

#include <string>
#include <iostream>

//
//Public functions
//
template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
  //rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
  //m_root = 0, nullptr, nullptr;
  m_root=nullptr;

}

//copyTree constructor
template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST(const BST<ItemType, KeyType>& tree)
{
  m_root=copy(tree.m_root);
}

//destructor
template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
  this->destroyTree(m_root);
}

//check if the item has no children
template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::isLeaf(BinaryNode<ItemType>* subtree)
{
  if(subtree->getleftChildPtr()==nullptr && subtree->getrightChildPtr()==nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

//Inserts newEntry into this binary search tree.
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::Add(const ItemType& newEntry) throw (NotFoundException)
{
   BinaryNode<ItemType>* newPtr = new BinaryNode<ItemType> (newEntry);
   m_root = RecAdd(m_root, newPtr);
}

//use Recursive function to add value in tree
template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::RecAdd(BinaryNode<ItemType>* subTreePtr,  BinaryNode<ItemType>* newNodePtr)
{
  // if (m_root==nullptr)
  // {
  //   return newtree;
  // }

  // else if (value<m_root->getItem())  
  // {
  //   //go to the left subtree
  //   m_root->getleftChildPtr();
  //   if (m_root==nullptr)
  //   {
  //     RecAdd (m_root, value);
  //   }
  //   else 
  //   {
  //   RecAdd(m_root->getleftChildPtr(), value);
  //   BinaryNode<T>* new_P = new BinaryNode<T>* (value);
  //   m_root->setleftPtr(leftChildPtr); 
  //   }
  // }
  // else if (value>m_root.getItem())
  // {
  //    //go to the right subtree
  //    m_root->getrightChildPtr();
  //    if (m_root == nullptr)
  //    {
  //       RecAdd (m_root, value);
  //    }
  //    else
  //    {
  //      RecAdd(m_root->getrightChildPtr(), value);
  //      BinaryNode<T>* new_P = new BinaryNode<T>* (value);
  //      m_root->setleftPtr(rightChildPtr); 
  //    }
  // }

  if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else 
    {
        BinaryNode<ItemType>* leftPtr = subTreePtr->getleftChildPtr();
        BinaryNode<ItemType>* rightPtr = subTreePtr->getrightChildPtr();
        if((subTreePtr->getItem().getAN())>(newNodePtr->getItem().getAN()))
        {
            leftPtr=RecAdd (leftPtr,newNodePtr);
            subTreePtr->setleftPtr(leftPtr);
        }
        else
        {
            rightPtr=RecAdd(rightPtr,newNodePtr);
            subTreePtr->setrightPtr(rightPtr);
        }
        return subTreePtr;
    }
}

//Removes the given entry from this binary search tree
//return true if it removed, otherwise return false.
template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::remove(const KeyType& target)
{
  if(search(target)==true)//check if the target is exist
    {
        m_root = removeValue(m_root,target);//call removeValue method
        return true;
    }
    else
    {
        return false;
    }
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
  if(search(aKey) == true)
  {
      return (findNode(m_root, aKey)->getItem());
  }
  else
  {
    throw NotFoundException("Cannot found it! ");
  }
}

// template <typename ItemType>
// void BST<ItemType, KeyType>::setItem(const T& value)
// {
//   entry=value;
// }

//Searches the binary search tree for a given target value.
template <typename ItemType, typename KeyType>
bool BST<ItemType, KeyType>::search(const KeyType& aKey) const
{
  if(findNode(m_root,aKey)==nullptr)
    {
        return false;
    }
    else
    {   
        return true;    
    }
}

//
//Traversals Functions
//
template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::inorderTraverse(void visit(ItemType&)) const
{
    inorder(visit, m_root);
}
template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::preorderTraverse(void visit(ItemType&)) const
{
    preorder(visit, m_root);
}
template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::postorderTraverse(void visit(ItemType&)) const
{
    postorder(visit, m_root);
}


//
//Private
//
// Recursively deletes all nodes from the tree.
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
     if (subTreePtr != nullptr)
       {
          destroyTree(subTreePtr->getleftChildPtr());//destroy the left subtree
          destroyTree(subTreePtr->getrightChildPtr());//destroy the right subtree
          delete subTreePtr;
       }
}

//remove the target Value from a subtree
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::removeValue(BinaryNode<ItemType>* subTreePtr, const KeyType& target)
{
  if(subTreePtr==nullptr)
    {
        return nullptr;
    }
    else if(subTreePtr->getItem().getAN()==target)
    {
        subTreePtr = removeNode(subTreePtr);//call removeNode method to remove the node with target
        return subTreePtr;
    }
    else if(subTreePtr->getItem().getAN() > target)
    {
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getleftChildPtr(), target);
        subTreePtr->setleftPtr(temp);
        return subTreePtr;
    }
    else
    {
        BinaryNode<ItemType>* temp = removeValue(subTreePtr->getrightChildPtr(), target);
        subTreePtr->setrightPtr(temp);
        return subTreePtr;
    }
}

//remove the node which have target value
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::removeNode( BinaryNode<ItemType>* nodePtr)
{
  if(nodePtr->isLeaf())
    {
        delete nodePtr;//remove the node
        nodePtr=nullptr;
        return nodePtr;
    }
    else if((nodePtr->getleftChildPtr()==nullptr||nodePtr->getrightChildPtr()==nullptr)&&!nodePtr->isLeaf())
    {
        BinaryNode<ItemType>* nodeconnectPtr;//create a connector pointer
        if(nodePtr->getleftChildPtr()!=nullptr)
        {
            nodeconnectPtr=nodePtr->getleftChildPtr();
        }
        else
        {
            nodeconnectPtr=nodePtr->getrightChildPtr();
        }
        delete nodePtr;
        nodePtr = nullptr;
        return nodeconnectPtr;
    }
    else
    {
        ItemType newValue;
        BinaryNode<ItemType>* temp = removeLeftmostNode(nodePtr->getrightChildPtr(), newValue);
        nodePtr->setrightPtr(temp);
        nodePtr->setItem(newValue);
        return nodePtr;
    }
}

//switch node.
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& inorderSuccessor)
{
    if(nodePtr->getleftChildPtr()==nullptr)
    {
        inorderSuccessor = nodePtr->getItem();
        return removeNode(nodePtr);        
    }
    else
    {
        return removeLeftmostNode(nodePtr->getleftChildPtr(), inorderSuccessor);
    }
}

//// Returns a pointer to the node containing the given value
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::findNode( BinaryNode<ItemType>* subTreePtr, const KeyType& target) const 
{
    if(subTreePtr==nullptr)
    {
        return nullptr;
    }
    else if(subTreePtr->getItem().getAN() ==target)
    {
        return subTreePtr;
    }
    else if(subTreePtr->getItem().getAN()>target)
    {
        return findNode(subTreePtr->getleftChildPtr(),target);
    }
    else
    {
        return findNode(subTreePtr->getrightChildPtr(),target);
    }
}
//deep copy constructor
template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::copy(const BinaryNode<ItemType>* treePtr) const
{
    BinaryNode<ItemType>* newTreePtr = nullptr;
    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr)
    {
      // Copy node
      newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(), nullptr, nullptr);
      newTreePtr->setleftPtr(copy(treePtr->getleftChildPtr()));
      newTreePtr->setrightPtr(copy(treePtr->getrightChildPtr()));  
      // Else tree is empty (newTreePtr is nullptr)
    }
    return newTreePtr;
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::inorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr != nullptr)
   {
      inorder(visit, treePtr->getleftChildPtr());
      ItemType theItem = treePtr->getItem();
      visit(theItem);//do visit method
      inorder(visit, treePtr->getrightChildPtr());
   }  // end if
}

template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::preorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr != nullptr)
   {
      ItemType theItem = treePtr->getItem();
      visit(theItem);//do visit method
      preorder(visit, treePtr->getleftChildPtr());//call preorder method
      preorder(visit, treePtr->getrightChildPtr());//call preorder method
   }  // end if
}
template<typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::postorder( void visit(ItemType&), BinaryNode<ItemType>* treePtr) const 
{
    if (treePtr->getleftChildPtr()!= nullptr)
   {
      postorder(visit, treePtr->getleftChildPtr());//call postorder method
      //BinaryNode<ItemType>* left = treePtr->getleftChildPtr();
      //ItemType leftItem = left->getItem();
      //visit(leftItem);//do visit method
   }
   if (treePtr->getrightChildPtr()!= nullptr)
   {
      postorder(visit, treePtr->getrightChildPtr());//call postorder method
      //BinaryNode<ItemType>* Right = treePtr->getrightChildPtr();
      //ItemType rightItem = Right->getItem();
      //visit(rightItem);//do visit method
   }
   ItemType theItem = treePtr->getItem();
   visit(theItem);//do visit method
}
