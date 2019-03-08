/**
*	@file :Selection.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A header file for templated Selection class
*/
#include <string>
#ifndef SELECTION_H
#define SELECTION_H

using namespace std;
template<class ItemType>
class Selection
{
    public:
    //constructor
    Selection(ItemType array[], int n);
    int findIndexofLargest(const ItemType array[], int a_size);

    private:

};
#include "Selection.hpp"
#endif