/**
*	@file :BinaryNode.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for template BinaryNode class
*           Models a single tree node: to hold a data entry,
*           left and right sub-trees. 
*/

#ifndef BINARYNODE_H
#define BINARYNODE_H

template<typename T>
class BinaryNode
{
    public:
    //constructor
    BinaryNode();
    BinaryNode(const T& value);
    BinaryNode(const T& value,
               BinaryNode<T>* leftChildPtr,
               BinaryNode<T>* rightChildPtr);
    //check whether it's an empty tree
    bool isLeaf() const;

    //set and get fouctions
    void setItem(const T& value);
    T getItem() const;

    //setNext and getNext functions
    void setleftPtr(BinaryNode<T>* leftChildPtr);
    void setrightPtr(BinaryNode<T>* rightChildPtr);
    BinaryNode<T>* getleftChildPtr() const;
    BinaryNode<T>* getrightChildPtr() const;

    //destructor
    ~BinaryNode();

    private:
    T Item;
    BinaryNode<T>* leftPtr;   // Pointer to left child
    BinaryNode<T>* rightPtr;  // Pointer to right child

};// end BinaryNode

#include "BinaryNode.hpp"
#endif

//add to makefile
//BinaryNode.hpp BinaryNode.h BST.hpp BST.h
