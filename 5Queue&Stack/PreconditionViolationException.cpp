/*
*	@file :PreconditionViolationException.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A method file for PreconditionViolationException class
*/
#include <stdexcept>
#include <string>
#include "PreconditionViolationException.h"  

PreconditionViolationException::PreconditionViolationException(std::string msg):std::runtime_error("PreconditionViolationException: "+msg)
{
}  // end constructor

// End of implementation file.