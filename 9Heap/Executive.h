/**
*	@file :Executive.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A header file for Executive class
*          
*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>

// #include "BinaryNode.h"
// #include "MinHeap.h"
// #include "HeapInterface.h"

using namespace std;

class Executive
{
    public:
        //constructor
        Executive();
        //read file
        void Exec();

    private:
    //priority
    string m_p;
    //package content
    string m_c;
    //destination
    string m_d;
    //Notice the Truck
    string m_truck;
    //numbers of packages the truck holds
    int m_num;
    string truck;
};
#endif