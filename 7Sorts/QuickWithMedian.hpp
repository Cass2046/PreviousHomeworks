/**
*	@file :Quick.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A header file for templated Quick class
*/

#include <iostream>
#include <string>
#include "QuickWithMedian.h"
using namespace std;
static const int MIN_SIZE1  = 10; // Smallest size of an array that quicksort will sort

template<class ItemType>
QuickWithMedian<ItemType>::QuickWithMedian(ItemType theArray[], int n)
{
    QuickSort(theArray, 0, n-1);
}

template<class ItemType>
void QuickWithMedian<ItemType>::insertionSort(ItemType theArray[], int first, int last)
{
   // unsorted region array[unsorted..n-1]
   for (int unsorted = first + 1; unsorted <= last; unsorted++)
   {
      ItemType nextItem = theArray[unsorted];
      int loc = unsorted;
      while ((loc > first) && (theArray[loc - 1] > nextItem))
      {
         // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         loc--;
      }  // end while
      
      // At this point, theArray[loc] is where nextItem belongs
      theArray[loc] = nextItem; // Insert nextItem into sorted region
   }
} 

template<class ItemType>
void QuickWithMedian<ItemType>::order(ItemType theArray[], int i, int j)
{
   if (theArray[i] > theArray[j])
      std::swap(theArray[i], theArray[j]); // Exchange entries
}

template<class ItemType>
int QuickWithMedian<ItemType>::sortFirstMiddleLast(ItemType theArray[], int first, int last)
{
   int mid = first + (last - first) / 2;
   order(theArray, first, mid); // Make theArray[first] <= theArray[mid]
   order(theArray, mid, last);  // Make theArray[mid] <= theArray[last]
   order(theArray, first, mid); // Make theArray[first] <= theArray[mid]
   
   return mid;
}

template<class ItemType>
int QuickWithMedian<ItemType>::partition(ItemType theArray[], int first, int last)
{
   // Choose pivot using median-of-three selection
   int pivotIndex = sortFirstMiddleLast(theArray, first, last);
   
   // Reposition pivot so it is last in the array
   std::swap(theArray[pivotIndex], theArray[last - 1]);
   pivotIndex = last - 1;
   ItemType pivot = theArray[pivotIndex];
   
   // Determine the regions S1 and S2
   int indexFromLeft = first + 1;
   int indexFromRight = last - 2;
   
   bool done = false;
   while (!done)
   {
      // Locate first entry on left that is >= pivot
      while (theArray[indexFromLeft] < pivot)
         indexFromLeft = indexFromLeft + 1;
      
      // Locate first entry on right that is <= pivot
      while (theArray[indexFromRight] > pivot)
         indexFromRight = indexFromRight - 1;
      
      if (indexFromLeft < indexFromRight)
      {
         std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
         indexFromLeft = indexFromLeft + 1;
         indexFromRight = indexFromRight - 1;
      }
      else
      {
        done = true;
      }
   }
   
   // Place pivot in proper position between S1 and S2, and mark its new location
   std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
   pivotIndex = indexFromLeft;
   
   return pivotIndex;
} 

template<class ItemType>
void QuickWithMedian<ItemType>::QuickSort(ItemType theArray[], int first, int last)
{
   if (last - first + 1 < MIN_SIZE1)
   {
      insertionSort(theArray, first, last);
   }
   else
   {
      // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, first, last);
      
      // Sort subarrays S1 and S2
      QuickSort(theArray, first, pivotIndex - 1);
      QuickSort(theArray, pivotIndex + 1, last);
   }  // end if
}  
