/**
*	@file :Executive.cpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A method file for Executive class
*           
*/
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cstddef>
#include <stdexcept>

#include "Package.h"
#include "Heap.h"
// #include "HeapInterface.h"
#include "Executive.h"
using namespace std;

//constructor
Executive::Executive()
{
    //priority
    m_p="";
    //package content
    m_c="";
    //destination
    m_d="";
    //Notice the Truck
    m_truck="";
    //numbers of packages the truck holds
    m_num=0;
}

//read file
void Executive::Exec()
{
    //read from the given file
    string filename;
    cout<<"Input filename:"<<endl;
    cin>>filename;
    ifstream inp;
    inp.open(filename);
    string m;
    Heap<Package> H(1);
    try
    {//expection
    while (!inp.eof())
    {
        getline(inp, m, ',');
        if (m!="TRUCK")
        {
            m_p=m;
            getline(inp, m_c, ',');
            getline(inp, m_d);
            int level=0;
            if(m_p=="overnight")
            {
                level = 0;
            }
            else if(m_p=="2-Day")
            {
                level = 1;
            }
            else if(m_p=="ground")
            {
                level = 2;
            }
            else if(m_p=="whenever")
            {
                level = 3;
            }
            Package P(level, m_p, m_c, m_d);
            H.add(P);
        }
        //while it reads "TRUCK"
        else if (m=="TRUCK")
        {
            string num;
            int ms_num;
            getline(inp, num);
            ms_num=stoi(num);
            cout<<"* * * * * * * * * * * * * "<<endl;
            cout<<"Truck has arrived!"<<endl;
            cout<<"Loading the following packages:"<<endl;
            int s=H.size();
            if(ms_num<=s)
            {
            for(int i=1;i<=ms_num;i++)
            {
                cout<<i<<". Priority: "<<H.peekTop().getPriorityS()<<"; Contents: "<<H.peekTop().getContent()<<"; Destination: "<<H.peekTop().getDis()<<endl;
                H.remove();
            }
            }

            else
            {
                for(int i=1;i<=s; i++)
                {
                    cout<<i<<". Priority: "<<H.peekTop().getPriorityS()<<"; Contents: "<<H.peekTop().getContent()<<"; Destination: "<<H.peekTop().getDis()<<endl;
                    H.remove();
                }

                for(int i=1;i<=(ms_num-s); i++)
                {
                    cout<<H.peekTop().getPriorityS()<<H.peekTop().getContent()<<H.peekTop().getDis()<<endl;
                    H.remove();
                }
            }
        
            cout<<"Truck is leaving!"<<endl;
        }
    }
    }
    catch (runtime_error e)
    {
        cout<<e.what()<<endl;
    }
    inp.close();
}