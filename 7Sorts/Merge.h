/**
*	@file :Merge.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A header file for Merge class
*/

#ifndef MERGE_H
#define MERGE_H
#include <string>
using namespace std;
template<class ItemType>
class Merge
{
    public:
    //constructor
    Merge(ItemType theArray[], int n);
	void merge(ItemType theArray[], int first, int mid, int last, ItemType tempArray[]);//merge method
    void mergeSort(ItemType theArray[], int first, int last, ItemType tempArray[]);//mergsort method
    
    private:
};
#include "Merge.hpp"
#endif