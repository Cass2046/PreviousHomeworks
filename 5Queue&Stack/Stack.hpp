/*
*	@file :Stack.hpp
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief Run methods for Template Stack class
*/

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

template <typename T>
Stack<T>::Stack()   //An empty list is created.
{
  s_front=nullptr;    //null pointer
  s_length=0;         //initilize a length
}

template <typename T>
Stack<T>::~Stack()
{

}

template <typename T>
bool Stack<T>::isEmpty() const
{
  //returns true if the stack is empty, false otherwise
	if (s_front == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Entry added to top of stack
//throws PreconditionViolationException if push cannot occur (e.g. stack full)  
//Like linkedlist's addfront method
template <typename T>
void Stack<T>::push(const T value) throw(PreconditionViolationException)
{
  Node<T>*n = new Node<T> ();  //create a new node for temporary use

  //empty LIST
  if (s_length == 0)
  {
    n->setItem(value);
    s_front = n;
    s_length++;
    n=nullptr;
    delete n;
  }
  else if (s_length != 0)
  {
    n->setItem(value);
    n->setNext(s_front);
    s_front = n;
    s_length++;
    n=nullptr;
    delete n;
  }
  else
  {
    throw(PreconditionViolationException(" Push attempted on an full Stack. "));
  }
}

//assumes the stack is not empty top of the stack is removed
//throws PreconditionViolationException when a pop is attempted on an empty stack.
//Like linkedlist's removefront method
template <typename T>
void Stack<T>::pop() throw(PreconditionViolationException)
{
  Node<T>* cur=s_front;
  if (s_front == nullptr)  //empty list
  {
    cur=nullptr;   //delete pointer
    delete cur;    //delete value
    throw(PreconditionViolationException("Pop attempted on an empty stack"));
  }
  else
  {
    s_front=s_front->getNext();
    cur=nullptr;   //delete pointer
    delete cur;    //delete value
    s_length--;
  }
}

//assumes the stack is not empty, returns the value at the top of the stack
//throws a PreconditionViolationException is attempted on an empty stack. 
//Does not return a value in this case.
template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException)
{
  Node<T>*p=s_front; //find the front
  if (p!=nullptr)
  {
    return p->getItem();
  }
  else
  {
    throw(PreconditionViolationException(" The theater is empty. "));
  }
}


// //found which one to remove
// template <typename T>
// bool Stack<T>::removeAt(int position)
// {
//   Node<T>* cur=s_front;
//   Node<T>* n=nullptr;
//   if (position == 1)  //remove the first
//   {
//     s_front=s_front->getNext();
//     s_length--;
//     std::cout<<cur->getItem()<<" left the theater."<<std::endl;
//     return true;
//     delete cur;
//   }
//   else if ((position<1) || (position>s_length+1))  //less or more than
//   {
//     return false;
//   }
//   else
//   {
//     int pos=1;
//     while (pos<position)
//     {
//       n=cur;
//       cur=cur->getNext();
//       pos++;
//     }
//     n->setNext(cur->getNext());
//     cur=nullptr;
//     s_length--;
//     std::cout<<cur->getItem()<<" left the theater."<<std::endl;
//     return true;
//     delete cur;
//   }
// }
