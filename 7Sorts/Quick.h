/**
*	@file :QuickWithMedian.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A header file for QuickWithMedian class
*/

#ifndef QUICK_H
#define QUICK_H
#include <string>
template<class ItemType>
class Quick
{
	public:
        Quick(ItemType theArray[], int n);
        void Quicksort(ItemType theArray[], int first, int last);
	void insertionSort(ItemType theArray[], int first, int last);
        void order(ItemType theArray[], int i, int j);
        int sortFirstMiddleLast(ItemType theArray[], int first, int last);
        int partition(ItemType theArray[], int first, int last);
	private:

};
#include "Quick.hpp"
#endif
