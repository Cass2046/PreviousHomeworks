/**
*	@file :MazeRunner.h
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief A header file for MazeRunner class
*/

#ifndef MAZERUNNER_H
#define MAZERUNNER_H

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>


class MazeRunner
{
    public:
     //constructor
    //Maze pointer is ready to go through the Maze
    MazeRunner(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);

    //destructor
    ~MazeRunner();

    //The maze is tracersed until the it exited
    //or all possibilities are exhausted
    //return true if it reached the exit, otherwise false
    bool runMaze();

    //print out the 2D array
    void print();

    //return a which has been visited in array
    const int* const* getVisited() const;

    //return how many row has been visited
    int getVisitedRow() const;

    //return how many collumn has been visited
    int getVisitedCol() const;

    //return a const pointer to maze
    const char* const* getMaze() const;

    //try in order of up/right/down/left
	bool solveMaze(const char* const* s_M, int r, int c,int** sol);

    //check this is step if can be counted
	bool isSafe(const char* const* maze, int r, int c,int** solv);

    private:
    const char* const* m_maze;
	int** m_visited;
	int m_rows, m_cols;
	int m_curRow, m_curCol;
	int m_StartRow, m_StartCol;
	int m_curStep;

};
#endif
