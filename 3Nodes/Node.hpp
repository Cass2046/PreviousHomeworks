/**
*	@file :Node.hpp
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A method file for templated Node class
*/

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

template <typename T>
Node<T>::Node()  //constructor
{
  n_value;
  n_next=nullptr;
}

template <typename T>
Node<T>::~Node()  //destructor
{

}

//
// get and set Methods
//
template <typename T>
void Node<T>::setItem(T value)
{
  n_value = value;
}

template <typename T>
T Node<T>::getItem()
{
  return n_value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
  n_next = next;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
  return n_next;
}



