/**
*	@file :Selection.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for templated Selection class
*/
#include <iostream>
#include <string>
#include "Selection.h"
using namespace std;

template<class ItemType>
Selection<ItemType>::Selection(ItemType array[], int n)
{
    for (int i= n - 1; i>= 1; i--)
    {
      // Select the largest entry in the array
      int l = findIndexofLargest(array, i+1);
      // Swap the largest one
      std::swap(array[l], array[i]);
    } 

}

template<class ItemType>
int Selection<ItemType>::findIndexofLargest(const ItemType array[], int n)
{
   int index = 0; // Index of largest entry found so far
   for (int cur = 1; cur < n; cur++)
   {
      if (array[cur] > array[index])
      {
         index = cur;
      }
   } 
   return index; // Index of largest entry
} 

