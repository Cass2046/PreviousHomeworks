/**
*	@file :Heap.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for template MinHeap class
*           
*/

#ifndef HEAP_H
#define HEAP_H
#include <cstddef>
#include <string>
#include <stdexcept>
#include "HeapInterface.h"
using namespace std;

template<typename T>
class Heap: public HeapInterface<T>
{
    public:
    //constructor
    Heap(int size);
    Heap(const Heap<T>& heap);
    //descructor
    ~Heap();
    //check if the item has no children
    //bool isLeaf(BinaryNode<ItemType>* subtree);
    //Sort the package depending on the priority
    //int priority(BinaryNode<Itemtyp>* subtree) throw (runtime_error);
    //Inserts newEntry into min heap tree
   

//returns true if empty, false otherwise
    bool isEmpty() const;
    //returns size of the heap
    int size() const;
    //option to throw exception based on implementation
    void add(T value);
    //throws exception if there is nothing to remove
    void remove() throw(std::runtime_error);
    //returns the item at the top of the heap
    T peekTop() throw (std::runtime_error);


    private:
    //creat an new array
    T* Tree;
    //priority
    int m_size; 
    int m_numItem;


};
#include "Heap.hpp"
#endif
    