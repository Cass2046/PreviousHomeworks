/**
*	@file :Executive.cpp
*	@author :Lu Yin
*	@date :2017.02.27
*	@brief Methods file for Exective class
*/

#include "Executive.h"
#include "MazeRunner.h"
#include "MazeReader.h"
#include "MazeCreationException.h"
#include <fstream>
#include <string>
#include <iostream>

Executive::Executive (char* name)
{
    try
    {
        MazeReader MR(name);
        const char* const* mazPtr = nullptr;
        int strow = 0;
        int stcol = 0;
        int trows = 0;
        int tcols = 0;
        mazPtr = MR.getMaze();
        strow = MR.getStartRow();
        stcol = MR.getStartCol();
        trows = MR.getRows();
        tcols = MR.getCols();

        MazeRunner MRR(mazPtr,strow, stcol, trows, tcols);
        run(MR,MRR);
     }
        catch (MazeCreationException e) {std::cout<<e.what()<<endl;}
}


    // std::string c;
    // //read the maze from file
    // std::ifstream inp;
    // inp.open(maze);
    // int row;
    // int col;
    // //starting position
    // int s_row;
    // int s_col;

    // while(!inp.eof())
    // {
    //     //read how many rows
    //     inp>>c;
    //     row=c;
    //     //read how many collumns
    //     inp>>c;
    //     col=c;
    //     //read the starting position
    //     inp>>c;
    //     s_row=c;
    //     inp>>c;
    //     s_col=c;
    //     std::cout<<"Starting position: "<<s_row<<", "<<s_col<<std:endl;
    //     std::cout<<"Size: "<<row<<", "<<col<<std::endl;
    // }


//run method
void Executive::run(MazeReader MR, MazeRunner MRR)
{
    std::cout<<"Starting position: "<<MR.getStartRow()<<","<<MR.getStartCol()<<std::endl;
    std::cout<<"Size: "<<MR.getRows()<<","<<MR.getCols()<<std::endl;
    
    if(MRR.runMaze()==true)
    {
        MRR.print();//print the 2D array
        std::cout<<"Escaped!"<<std::endl;
    }
    else
    {
        std::cout<<"No way out!"<<std::endl;
    }
}

Executive::~Executive()
{

}
