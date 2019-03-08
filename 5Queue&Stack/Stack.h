/*
*	@file :Stack.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for Template Stack class
*/
#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "StackInterface.h"
#include "PreconditionViolationException.h"

#include <string>

template <typename T>
class Stack: public StackInterface<T>
{
  public:
  //constructor
  Stack();

  //destructor
  ~Stack();

 bool isEmpty() const;

//add front
  void push(const T value) throw(PreconditionViolationException);

//remove front
  void pop() throw(PreconditionViolationException);

  T peek() const throw(PreconditionViolationException);

  private:
  Node<T>* s_front;
  int s_length;

};
#include "Stack.hpp"
#endif
