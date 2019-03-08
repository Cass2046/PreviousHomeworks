/**
*	@file :MazeReader.h
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief A header file for MazeReader class
*/

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

#include "MazeCreationException.h"


class MazeReader
{
    public:
    //constructor
    //Create a 2D char array. 
    //Throws MazeCreationExecption if the size 
    //or starting positiong is not allowed
    MazeReader(std::string file) throw(MazeCreationException);

    //destructor
    ~MazeReader();
    
    //Maze is read correctlly, return pointer to the Maze
    const char* const* getMaze() const;

    //if maze read correctlly, return how many rows in maze
    int getRows() const;

    //if maze read correctlly, return how many collumns in maze
    int getCols() const;

    //return starting position
    int getStartRow() const;

    int getStartCol() const;

    private:
    int m_row;
    int m_col;
    const char* const* M; //maze
    int ms_row;  //starting position
    int ms_col;
    char** m_maze;

};
#endif