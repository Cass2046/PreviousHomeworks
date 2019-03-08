io/**
*	@file :MazeRunner.cpp
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief Methods file for MazeRunner class
*/

#include "MazeRunner.h"
#include "MazeCreationException.h"

//constructor
MazeRunner::MazeRunner(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
{
    //initialize the all variable
    m_curStep=0;
    m_visited=new int*[rows];  //created a 1D array (row only)
    for(int i = 0; i < rows; i++) 
    {
      m_visited[i] = new int[cols];  //1D -> 2D array
    }
    m_StartRow=startRow;
    m_StartCol=startCol;
    m_rows=rows;
    m_cols=cols;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            m_visited[i][j]=0;
        }
    }
    m_visited[startRow][startCol]=m_curStep;
    m_curRow=startRow;
    m_curCol=startCol;
    m_maze=mazePtr;
}

//destructor
MazeRunner::~MazeRunner()
{
    for(int i = 0; i < m_rows; i++) 
    {
      delete [] m_visited[i];  //1D -> 2D array
    }
    delete [] m_visited;
}

bool MazeRunner::runMaze()
{
    //walk the Maze
    solveMaze(m_maze, m_curRow, m_curCol, m_visited);
    //check if there is a Exit to leave
    if(m_maze[m_curRow][m_curCol]=='E')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MazeRunner::print()
{
    for (int i=0; i<m_rows; i++)
    {
        for (int j=0; j<m_cols; j++)
        {
            std::cout<<m_visited[i][j];
             std::cout<<" ";
        }
        std::cout<<""<<std::endl;
    }
}

const int* const* MazeRunner::getVisited() const
{
     return m_visited;
}

int MazeRunner::getVisitedRow() const
{
    return m_curRow;
}

int MazeRunner::getVisitedCol() const
{
    return m_curCol;
}

const char* const* MazeRunner::getMaze() const
{
    return m_maze;
}

bool MazeRunner::solveMaze(const char* const* s_M, int r, int c,int** sol)
{
    if(isSafe(s_M,r,c,sol) == true)
    {
        m_curRow=r;
        m_curCol=c;
        m_curStep++;
        sol[m_curRow][m_curCol]=m_curStep;
      if(r!=0)
      {
          if(solveMaze(s_M,r-1,c,sol)==true)//up
        {
            return true;
        }
      }
      if(c!=m_cols-1)
      {
          if(solveMaze(s_M, r, c+1, sol)==true)//right
          {
              return true;
          }

        //m_curStep--;//return to last step
        //sol[m_curRow][m_curCol]=0;
        //return false;
      }
      if(r!=m_rows-1)
      {
          if(solveMaze(s_M, r+1, c, sol)==true)//down
          {
              return true;
          }
      }
      if(c!=0)
      {
          if(solveMaze(s_M, r, c-1, sol)==true)//left
          {
              return true;
          }
      }
      m_curStep--;
      sol[r][c]=0;
      return false;
    }

    // if the step is E, stop check
    else if (s_M[r][c]=='E'&& sol[r][c]==0)
    {
        m_curRow=r;
        m_curCol=c;
        m_curStep++;
        sol[r][c]=m_curStep;
        return true;
    }
    else
    {
        return false;
    }
}

bool MazeRunner::isSafe(const char* const* maze, int r, int c,int** solv)
{
    if(r>=0 && r<m_rows && c>=0 && c<m_cols)
    {
        if( maze[r][c]==' ' && solv[r][c]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
}
