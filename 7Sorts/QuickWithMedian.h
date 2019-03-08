/**
*	@file :Quick.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A header file for Quick class
*/

#ifndef QUICKWITHMEDIAN_H
#define QUICKWITHMEDIAN_H
#include <string>
using namespace std;
template<class ItemType>
class QuickWithMedian
{
    public:
    //constructor
    QuickWithMedian(ItemType theArray[], int n);
    void QuickSort(ItemType theArray[], int first, int last);
	void insertionSort(ItemType theArray[], int first, int last);
    void order(ItemType theArray[], int i, int j);
    int sortFirstMiddleLast(ItemType theArray[], int first, int last);
    int partition(ItemType theArray[], int first, int last);

    private:
};
#include "QuickWithMedian.hpp"
#endif