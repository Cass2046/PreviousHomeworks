/*
*	@file :QueueInterface.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief An Interface class
*/
#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include <string>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Node.h"

template <typename T>
class QueueInterface
{
    public:
    virtual ~QueueInterface() {};

    /** Sees whether this queue is empty.
    @return True if the queue is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    // Entry added to back of queue
    // throws exception should enqueue fail
    // Note: The interface allows for an exception to be thrown, 
    // but doesn't obligate an implementation
    //addback
    virtual void enqueue(const T value) throw(PreconditionViolationException) = 0;

    // assumes the queue is not empty
    // front of the front is removed
    // throws PreconditionViolationException if attempted on an empty queue. 
    //Does not return a value in this case.
    //remove front
    virtual void dequeue() throw(PreconditionViolationException) = 0;

    // assumes the queue is not empty
    // returns the value at the front of the stack
    // throws a PreconditionViolationException if attempted on an empty queue.
    // Does not return a value in this case.
    //remove front
    virtual T peekFront() const throw(PreconditionViolationException) = 0;
  
};
#endif