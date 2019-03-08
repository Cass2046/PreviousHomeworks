/**
*	@file :Executive.h
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A header file for Executive class
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include "StackInterface.h"
#include "QueueInterface.h"
#include "PreconditionViolationException.h"

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>


class Executive
{
    public:
    Executive();
    ~Executive();
    void run(char* name); //run method

    private:
    
};
#endif