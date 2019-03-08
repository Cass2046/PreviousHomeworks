/*
*	@file :PreconditionViolationException.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for PreconditionViolationException class
*/

#ifndef PRECONDITIONVIOLATIONEXCPTION_H
#define PRECONDITIONVIOLATIONEXCPTION_H

#include <stdexcept>
#include <string>

class PreconditionViolationException: public std::runtime_error
{
    public:
    PreconditionViolationException(std::string msg);

};
#endif