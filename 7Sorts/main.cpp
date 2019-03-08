#include "SortTimer.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>
using namespace std;
int main(int argc, char* argv[]) 
{
//pick a sort they want to time
    string sort = argv[1]; 
    //select the bounds for the size of the array
    int l_bound = atoi(argv[2]);  //transform int to string
    int u_bound = atoi(argv[3]);
    //select how much the array size will increase with each new timing
    int increase_num = atoi(argv[4]);  //transform int to string
    //provide the name of a desired output file to store timing data
    string file_name = argv[5];

    SortTimer exec(sort, l_bound, u_bound, increase_num, file_name);
    return 0;
}