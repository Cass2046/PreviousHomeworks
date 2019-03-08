/**
*	@file :MazeReader.cpp
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief Methods file for MazeReader class
*/

#include "MazeReader.h"
#include "MazeCreationException.h"


//constructor
MazeReader::MazeReader(std::string file) throw(MazeCreationException)
{
    std::ifstream inp;
    std::string temp = "";
    inp.open(file);  //open the maze file
    inp>>m_row;
    inp>>m_col;
    inp>>ms_row;
    inp>>ms_col;
    std::getline(inp,temp);

    //2D array 
    m_maze = new char* [m_row]; //1D array only the row
    //read through the file
    for (int i=0; i<m_row; i++)
    {
        m_maze[i]=new char[m_col]; //only the collum
    }
    
    //save the maze
    if(ms_row<=m_row)
    {
        for (int i=0; i<m_row; i++)
        {
            std::getline(inp,temp);  //read by line

            for (int j=0; j<m_col; j++)
            {
                m_maze[i][j]=temp[j];  //string is an array
            }
        }
        inp.close();
        M=m_maze;
    }

    else
    {
        throw MazeCreationException("Invailed starting position.");
    }

}

//destructor
MazeReader::~MazeReader()
{
    // for(int i=0;i<m_row;i++)
    // {
    //     for(int j=0;j<m_col;j++)
    //     {
    //         //m_maze[i][j]=' ';
    //         //delete m_maze[i][j];
    //     }
    // }
    // delete [] m_maze;
   
    // delete [] m_maze; //only the collum
    
    for (int i=0; i<m_row; i++)
    {
        delete [] m_maze[i];
    }
    delete [] m_maze;
}

const char* const* MazeReader::getMaze() const
{
    return M;
}

int MazeReader::getRows() const
{
    return m_row;
}

int MazeReader::getCols() const
{
    return m_col;
}

int MazeReader::getStartRow() const
{
    return ms_row;
}

int MazeReader::getStartCol() const
{
    return ms_col;
}





