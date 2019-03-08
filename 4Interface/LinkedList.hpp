/**
*	@file :LinkedList.cpp
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A header file for templated City class
*/

#include "SpaceShipInterface.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

template <typename T>
LinkedList<T>::LinkedList()   //An empty list is created.
{
  m_front=nullptr;    //null pointer
  m_length=0;         //initilize a length
}

template <typename T>
LinkedList<T>::~LinkedList()   //Deletes all nodes in the list.
{

}

template <typename T>
bool LinkedList<T>::isEmpty() const   //return true if the list is empty, false otherwise.
{
  if (m_length == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


template <typename T>
int LinkedList<T>::getlength() const   //return the number of elements in the list.
{
  return m_length;
}

//returns the index of the first node in the list that contains the value. Returns 0 otherwise.
template <typename T>
int LinkedList<T>::positionOf(T value) const
{
  int pos=1;
  Node<T>*p=m_front;
  while(p!=nullptr)
  {
      if(p->getItem()==value)
      {
          return pos;
      }
      else
      {
        pos++;
        p=p->getNext();
      }
  }
  return (0);
}

template <typename T>
void LinkedList<T>::addBack(T value)   //post One new element added to the end of the list.
{
    Node<T>*cur = m_front;
    Node<T>*temp = cur;
    Node<T>*n = new Node<T> ();
    //empty list
    if(m_length == 0)
    {
      n->setItem(value);
      m_front = n;
    }
    else
    {
      while(cur != nullptr)
      {
        temp=cur;
        cur=cur->getNext();   //point to the next node


      }
      temp->setNext(n);
      n->setItem(value);

    }
    m_length++;
    temp=nullptr;
    delete temp;
    cur=nullptr;
    delete cur;
     n=nullptr;
    delete n;
}

template <typename T>
void LinkedList<T>::addFront(T value)   //post One new element added to the front of the list.
{
  Node<T>*n = new Node<T> ();  //create a new node for temporary use

  //empty LIST
  if (m_length == 0)
  {
    n->setItem(value);
    m_front = n;
  }
  else
  {
    n->setItem(value);
    n->setNext(m_front);
    m_front = n;
  }
  m_length++;
  n=nullptr;
  delete n;
}

template <typename T>  //return true if the element was inserted false otherwise.
bool LinkedList<T>::insert(int position, T value)
{
  Node<T>*n = new Node<T>();
  n->setItem(value);
  if (position == 1)
  {
    n->setNext(m_front);
    m_front=n;
    m_length++;
    return true;
  }
  else if ((position < 1) || (position > m_length+2))  //less or more than
  {
    return false;
  }
  else
  {
    Node<T>* cur = m_front;
    int pos=1;
    while (pos<(position-1))
    {
      cur=cur->getNext();
      pos++;
    }
  n->setNext(cur->getNext());
  cur->setNext(n);
  m_length++;
  cur=nullptr;
  delete cur;
  return true;
  }
}

template <typename T>
bool LinkedList<T>::removeBack()
{
    Node<T>* pre=nullptr;
    Node<T>* cur=m_front;
    while(cur!=nullptr)
    {
        pre=cur;
        cur=cur->getNext();
    }
    if(pre==nullptr)  //empty list
    {
        return false;
    }
    else
    {
        pre=nullptr;
        delete pre;
        m_length--;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::removeFront()
{
  Node<T>* cur=m_front;
  if (m_front == nullptr)  //empty list
  {
    cur=nullptr;   //delete pointer
    delete cur;    //delete value
    return false;
  }
  else
  {
    m_front=m_front->getNext();
    cur=nullptr;   //delete pointer
    delete cur;    //delete value
    m_length--;
    return true;
  }

}

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
  Node<T>* cur=m_front;
  Node<T>* n=nullptr;
  if (position == 1)  //remove the first
  {
    m_front=m_front->getNext();
    delete cur;
    m_length--;
    return true;
  }
  else if ((position<1) || (position>m_length+1))  //less or more than
  {
    return false;
  }
  else
  {
    int pos=1;
    while (pos<position)
    {
      n=cur;
      cur=cur->getNext();
      pos++;
    }

    n->setNext(cur->getNext());
    cur=nullptr;
    delete cur;
    m_length--;
    return true;

  }

}

template <typename T> //set value in a position
void LinkedList<T>::setEntry(int position, T value)
{
  Node<T>* cur=m_front;
  int pos=1;
  while(pos<position)
  {
    cur=cur->getNext();
    pos++;
  }
  cur->setItem(value);

}

template <typename T>   //return the entry at the given position
T LinkedList<T>::getEntry( int position )
{
  // if((position<1)||(position>m_length))
  // {
  //    return nullptr;
  // }
  if(position>=1 && position<=m_length)
  {
      Node<T>* cur=m_front;
    int pos=1;
    while (pos<position)
     {
       cur=cur->getNext();
       pos++;
     }
    return cur->getItem();
  }
  else
  {
    return 0;

  }
}
