/**
*	@file :Bubble.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for templated Bubble class
*/

#include <iostream>
#include <string>
#include "Bubble.h"
using namespace std;

template<class ItemType>
Bubble<ItemType>::Bubble(ItemType array[], int n)
{
    int temp=0; //use temp to store values
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++) //j is at the front of i
        {
            if (array[j]>array[i])
            {
                temp=array[j];
                array[j]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
}
