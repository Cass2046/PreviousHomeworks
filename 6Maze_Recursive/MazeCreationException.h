/**
*	@file :MazeCreationException.h
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief A header file for MazeCreationException class
*/

#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class MazeCreationException : public logic_error
{
public:
   MazeCreationException(const string& message = "");
}; // end MazeCreationException
#endif