#include <iostream>
#include <string>
#include "Quick.h"
using namespace std;

static const int MIN_SIZE  = 10; // Smallest size of an array that quicksort will sort


template<class ItemType>
Quick<ItemType>::Quick(ItemType theArray[], int n)
{
    Quicksort(theArray, 0, n-1);
}
template<class ItemType>
void Quick<ItemType>::insertionSort(ItemType theArray[], int first, int last)
{
   
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
   }  // end for
}  // end insertionSort


template<class ItemType>
void Quick<ItemType>::order(ItemType theArray[], int i, int j)
{
   if (theArray[i] > theArray[j])
      std::swap(theArray[i], theArray[j]); // Exchange entries
}  // end order


template<class ItemType>
int Quick<ItemType>::sortFirstMiddleLast(ItemType theArray[], int first, int last)
{
   int mid = first + (last - first) / 2;
   order(theArray, first, mid); // Make theArray[first] <= theArray[mid]
   order(theArray, mid, last);  // Make theArray[mid] <= theArray[last]
   order(theArray, first, mid); // Make theArray[first] <= theArray[mid]
   
   return last;
}  // end sortFirstMiddleLast


template<class ItemType>
int Quick<ItemType>::partition(ItemType theArray[], int first, int last)
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
         done = true;
   }  // end while
   
   // Place pivot in proper position between S1 and S2, and mark its new location
   std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
   pivotIndex = indexFromLeft;
   
   return pivotIndex;
}  // end partition


template<class ItemType>
void Quick<ItemType>::Quicksort(ItemType theArray[], int first, int last)
{
   if (last - first + 1 < MIN_SIZE)
   {
      insertionSort(theArray, first, last);
   }
   else
   {
      // Create the partition: S1 | S2 | Pivot
      int pivotIndex = partition(theArray, first, last);
      
      // Sort subarrays S1 and S2
      Quicksort(theArray, first, pivotIndex - 1);
      Quicksort(theArray, pivotIndex + 1, last);
   }  // end if
}  // end quickSort
