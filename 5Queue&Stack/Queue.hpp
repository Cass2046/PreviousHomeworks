/*
*	@file :Queue.hpp
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief Run methods for StarTrekShip class
*/
#include "Queue.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

template <typename T>
Queue<T>::Queue()   //An empty list is created.
{
  q_front=nullptr;    //null pointer
  q_length=0;         //initilize a length
}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
bool Queue<T>::isEmpty() const
{
  //returns true if the stack is empty, false otherwise
	if (q_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Entry added to back of queue, throws exception should enqueue fail
// Note: The interface allows for an exception to be thrown, 
// but doesn't obligate an implementation
// like LinkedList's add back
template <typename T>
void Queue<T>::enqueue(const T value) throw(PreconditionViolationException)
{
    Node<T>*cur = q_front;
    Node<T>*temp = cur;
    Node<T>*n = new Node<T> ();

    //empty list
    if(q_length == 0)
    {
      n->setItem(value);
      q_front = n;
      q_length++;
      temp=nullptr;
      delete temp;
      cur=nullptr;
      delete cur;
    }
    else if (q_length !=0)
    {
      while(cur != nullptr)
      {
        temp=cur;
        cur=cur->getNext();   //point to the next node
      }
      temp->setNext(n);
      n->setItem(value);
      q_length++;
      temp=nullptr;
      delete temp;
      cur=nullptr;
      delete cur;
    } 
    else
    {
      throw(PreconditionViolationException("Enqueue attempted on an full Queue"));
    }   
}

// assumes the queue is not empty, front of the front is removed
// throws PreconditionViolationException if attempted on an empty queue. 
// Does not return a value in this case.
// like LinkedList's remove front
template <typename T>
void Queue<T>::dequeue() throw(PreconditionViolationException)
{
  Node<T>* cur=q_front;
  if (q_front != nullptr)  //empty list
  {
    q_front=q_front->getNext();
    cur=nullptr;   //delete pointer
    delete cur;    //delete value
    q_length--;
  }
  else
  {
    throw(PreconditionViolationException(" Dequeue attempted on an empty Queue "));
  }
}

// assumes the queue is not empty, returns the value at the front of the queue
// throws a PreconditionViolationException if attempted on an empty queue.
template <typename T>
T Queue<T>::peekFront() const throw(PreconditionViolationException)
{
  Node<T>*p=q_front; //find the front
  if (p!=nullptr)
  {
    return p->getItem();
  }
  else
  {
    throw(PreconditionViolationException(" peekFront attempted on an empty Queue"));
  }
}