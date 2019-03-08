/**
*	@file :Node.h
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A header file for templated Node class
*/
#ifndef Node_H
#define Node_H

template <typename T>
class Node
{
  public:
    //constructor
    Node();
    //donstructor
    ~Node();
    
    void setItem(T value);
    T getItem();
    void setNext(Node<T>* n_next);
    Node<T>* getNext();
   
  private:
  T n_value;
  Node<T>* n_next;  //point to the next one

  };
  #include "Node.hpp"
  #endif
