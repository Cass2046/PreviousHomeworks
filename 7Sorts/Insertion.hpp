/**
*	@file :Insertion.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A methodr file for templated Insertion class
*/

#include <iostream>
#include <string>
#include "Insertion.h"
using namespace std;

template<class ItemType>
Insertion<ItemType>::Insertion(ItemType array[], int n)
{
    for (int i= 1; i< n; i++)
   {
      // Find the right position (loc) in the array
      ItemType nextItem = array[i];
      int loc = i;
      while ((loc > 0) && (array[loc - 1] > nextItem))
      {
         // Shift the array[loc - 1] to the right
         array[loc] = array[loc - 1];
         loc--;
      }
      array[loc] = nextItem; // Insert nextItem into sorted region
   }
}
