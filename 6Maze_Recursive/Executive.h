/**
*	@file :Executive.h
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief A header file for Executive class
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

#include "MazeRunner.h"
#include "MazeReader.h"

class Executive
{
    public:
    //constructor
    Executive(char* name);
    ~Executive();
    void run(MazeReader MR, MazeRunner MRR); //run method

    private:
    
};
#endif