/**
*	@file :SortTimer.cpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for SortTimer class
*/
#include "SortTimer.h"
#include "Bubble.h"
#include "Selection.h"
#include "Merge.h"
#include "Insertion.h"
#include "Quick.h"
#include "QuickWithMedian.h"
#include <limits>
#include <stdio.h>
#include <math.h> 
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <time.h>
#include <cstdlib>

SortTimer::SortTimer(std::string sort, int l_bound, int u_bound, int increase_num, std::string file_name)
{
        
        clock_t t;
        std::ofstream file;  //create a new file named by sort
        file.open(file_name);
    if(sort=="bubble")
    {
        //Create output file
        
        file<<"<bubble time>"<<std::endl;            
        for (int i=l_bound; i<=u_bound; i=i+increase_num)
        {
                int m_array[i]; 
                for(int j=0; j<=i; j++)
                {
                        m_array[j]=rand() % i + 1;
                }  
                //start a timer
                t = clock();
                Bubble<int> B(m_array, i);
                //stop the time
                t = clock() - t;
                file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
        }
        file.close();
    }

    else if(sort=="insertion")
    {
        
        file<<"<insertion time>"<<std::endl;            
        for (int i=l_bound; i<=u_bound; i=i+increase_num)
        {
           int m_array[i]; 
           for(int j=0; j<=i; j++)
           {
                m_array[j]=rand() % i + 1;
           }  
            //start a timer
            t = clock();
            Insertion<int> I(m_array, i);
            //return the time
            t = clock() - t;
            file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
        }
        file.close();
    }
        
         else if(sort=="merge")
        {
                file<<"<merge time>"<<std::endl;            
                for (int i=l_bound; i<=u_bound; i=i+increase_num)
                {
                    int m_array[i]; 
                    for(int j=0; j<=i; j++)
                    {
                        m_array[j]=rand() % i + 1;
                    }  
                    //start a timer
                    t = clock();
                    Merge<int> m(m_array, i);
                    //return the time
                    t = clock() - t;
                    file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
                }
                file.close();
        }
         else if(sort=="selection")
        {
                file<<"<selection time>"<<std::endl;            
                for (int i=l_bound; i<=u_bound; i=i+increase_num)
                {
                    int m_array[i]; 
                    for(int j=0; j<=i; j++)
                    {
                        m_array[j]=rand() % i + 1;
                    }  
                    //start a timer
                    t = clock();
                    Selection<int> s(m_array, i);
                    //stop the time
                    t = clock() - t;
                    file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
                }
                file.close();
        }
         else if(sort=="quick")
        {
                file<<"<quick time>"<<endl;            
                for (int i=l_bound; i<=u_bound; i=i+increase_num)
                {
                    int m_array[i]; 
                    for(int j=0; j<=i; j++)
                    {
                        m_array[j]=rand() % i + 1;
                    }  
                    //start a timer
                    t = clock();
                    Quick<int> quick(m_array, i);
                    //stop the time
                    t = clock() - t;
                   file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
                }
                file.close();
        }
         else if(sort=="quickWithMedian")
        {
                file<<"<quickWithMedian time>"<<endl;            
                for (int i=l_bound; i<=u_bound; i=i+increase_num)
                {
                    int m_array[i]; 
                    for(int j=0; j<=i; j++)
                    {
                        m_array[j]=rand() % i + 1;
                    }  
                    //start a timer
                    t = clock();
                    QuickWithMedian<int> QWM(m_array, i);
                    //stop the time
                    t = clock() - t;
                   file<<i<<","<<((float)t)/CLOCKS_PER_SEC<<std::endl;
                }
                file.close();
        }
    
}