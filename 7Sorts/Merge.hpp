/**
*	@file :Merge.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for templated Merge class
*/

#include <iostream>
#include <string>
#include "Merge.h"
using namespace std;

template<class ItemType>
Merge<ItemType>::Merge(ItemType theArray[], int n)
{
	ItemType* tempArray = new ItemType[n];  // Temporary array
	mergeSort(theArray, 0, n-1, tempArray);
	delete [] tempArray;
}

template<class ItemType>
void Merge<ItemType>::merge(ItemType theArray[], int first, int mid, int last, ItemType tempArray[])
{
   // Initialize the local indices to indicate the subarrays
   int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray
   
   // While both subarrays are not empty, copy the
   // smaller item into the temporary array
   int index = first1;            // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
      // At this point, tempArray[first..index-1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }
      index++;
   }
   
   // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }
   
   // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
      // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }
   
   // Copy the result back into the original array
   for (index = first; index <= last; index++)
      theArray[index] = tempArray[index];
}

template<class ItemType>
void Merge<ItemType>::mergeSort(ItemType theArray[], int first, int last, ItemType tempArray[])
{
   if (first < last)
   {
      // Sort each half
      int mid = (first + last) / 2; // Index of midpoint
      
      // Sort left half theArray[first..mid]
      mergeSort(theArray, first, mid, tempArray);
      
      // Sort right half theArray[mid+1..last]
      mergeSort(theArray, mid + 1, last, tempArray);
      
      // Merge the two halves
      merge(theArray, first, mid, last, tempArray);
   }
}


