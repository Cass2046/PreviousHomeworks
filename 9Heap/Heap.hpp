/**
*	@file :Heap.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for template MinHeap class
*/
#include "Package.h"
//#include "HeapInterface.h"
#include <cstddef>
#include <string>
#include <stdexcept>


using namespace std;
//constructor
template<typename T>
Heap<T>::Heap(int size)
{
    m_size = size;
    //creat an new array
    Tree=new T[size];
    //priority  
    m_numItem = 0;
}
template<typename T>
Heap<T>::Heap(const Heap<T>& heap)
{
    m_size=heap.m_size;//copy the size
	m_numItem = heap.m_numItem;//copy the number of Item
	Tree = new T[m_size];//create a new array
	for(int i = 0; i < m_numItem; i++)
	{
		Tree[i]=heap.Tree[i];//copy the array
	}
}
//descructor
template<typename T>
Heap<T>::~Heap()
{
    delete[] Tree;
}



 
//returns true if empty, false otherwise
template<typename T>
bool Heap<T>::isEmpty() const
{
    if (m_numItem==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//returns size of the heap
template<typename T>
int Heap<T>::size() const
{
    return m_numItem;
}

//option to throw exception based on implementation
template<typename T>
void Heap<T>::add(T value)
{   
    if(m_numItem >= m_size)
    {
        //enlarge the size
        m_size=m_size*2;
        T* temp = new T[m_size];
        for(int i=0; i < m_numItem;i++)
        {
            temp[i]=Tree[i];               
        }
        delete[] Tree;
        Tree = temp;
        Tree[m_numItem] = value;
    }
    else
    {
        Tree[m_numItem] = value;
    }
    int childIndex = m_numItem;
    int parentIndex=0;
    bool change = false;
    while(childIndex > 0 && change==false)
    {
        parentIndex = (childIndex-1)/2;
        if(value.getPriority()<Tree[parentIndex].getPriority())
        {
            swap(Tree[parentIndex],Tree[childIndex]);
            childIndex = parentIndex;
        }
        else
        {
            change = true;
        }
    }
    m_numItem++;
    
}


//throws exception if there is nothing to remove
template<typename T>
void Heap<T>::remove() throw(std::runtime_error)
{
    //replace with root w/ lowest rightest value
    //delete the beginning of the array
    if(isEmpty()==true)
    {
        throw(runtime_error("There is nothing to remove"));
    }
    else
    {   
        Tree[0] = Tree[m_numItem-1];
        //delete       
        m_numItem--;
        
        T* temp = new T[m_size];
        for(int i=0; i < m_numItem;i++)
        {
            temp[i]=Tree[i];               
        }
        delete[] Tree;
        Tree = temp;
        
        //exchange
        int childIndex = 1;
        int ParentIndex = 0;
        bool ischange = false;
        while(childIndex < m_numItem && ischange == false)
        {
            //get the min priority index
            if(m_numItem % 2 == 0 && (childIndex+1)== m_numItem)
            {
                ischange = false;
                //childIndex=childIndex;
            }
            else if(Tree[childIndex].getPriority()>Tree[childIndex+1].getPriority())
            {
                childIndex=childIndex+1;
            }
            if(Tree[childIndex].getPriority() < Tree[ParentIndex].getPriority())
            {
                swap(Tree[childIndex],Tree[ParentIndex]);
                ParentIndex = childIndex;
                childIndex = 2*ParentIndex+1;
            }
            else
            {
                ischange = true;
            }
        }
    }
}

//returns the item at the top of the heap
template<typename T>
T Heap<T>::peekTop() throw(std::runtime_error) 
{
    if (isEmpty()==true)
    {
        throw(runtime_error("The warehouse is EMPTY!"));
    }
    else
    {
        return Tree[0];    
    }
}
