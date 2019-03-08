/*
*	@file :StackInterface
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief An Interface class
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <stdexcept>
#include "Node.h"
#include "Stack.h"
#include "PreconditionViolationException.h"

template <typename T>
class StackInterface
{
    public:
    virtual ~StackInterface() {};

    /** Sees whether this stack is empty.
    @return True if the stack is empty, or false if not. */
    virtual bool isEmpty() const = 0;

    //Entry added to top of stack
    //throws PreconditionViolationException 
    //if push cannot occur (e.g. stack full)  
    //add front
    virtual void push(const T value) throw(PreconditionViolationException) = 0;

    //assumes the stack is not empty
    //top of the stack is removed
    //throws PreconditionViolationException when a pop is attempted on an empty stack.
    //Does not return a value in this case.
    //remove front
    virtual void pop() throw(PreconditionViolationException) = 0;

    //assumes the stack is not empty
    //returns the value at the top of the stack
    //throws a PreconditionViolationException is attempted on an empty stack. 
    //Does not return a value in this case.
    virtual T peek() const throw(PreconditionViolationException) = 0;

};
#endif