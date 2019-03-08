/*
*	@file :Queue.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for Template Queue class
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "PreconditionViolationException.h"
#include "QueueInterface.h"
#include "Node.h"

template <typename T>
class Queue: public QueueInterface<T>
{
  public:
  //constructor
  Queue();

  //destructor
  ~Queue();

  bool isEmpty() const;

//add back
  void enqueue(const T value) throw(PreconditionViolationException);

//remove front
  void dequeue() throw(PreconditionViolationException);

  T peekFront() const throw(PreconditionViolationException);



  private:
  Node<T>* q_front;
  int q_length;

};
#include "Queue.hpp"
#endif
