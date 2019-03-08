/**
*	@file :HeapInterface.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for HeapInterfacd class
*           
*/

#ifndef HEAPINTERFACE_H
#define HEAPINTERFACE_H

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <limits>
#include <cstddef>
#include "Heap.h"

template<typename T>
class HeapInterface
{
    public:

    virtual ~HeapInterface() { };

//returns true if empty, false otherwise
    virtual bool isEmpty() const = 0;

//returns size of the heap
    virtual int size() const = 0; 

//option to throw exception based on implementation
    virtual void add(T value) = 0; 

//throws exception if there is nothing to remove
    virtual void remove() throw(std::runtime_error) = 0; 

 //returns the item at the top of the heap
    virtual T peekTop() throw(std::runtime_error) = 0;

};
#endif

