/**
*	@file :Package.h
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A header file for Package class
*          
*/

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
//#include "HeapInterface"

using namespace std;

class Package
{
    public:
    //constructor
    Package();
    Package(int pl, string p, string c, string d);
    //get&set Priority functions
    void setPriority(int pl);
    int getPriority();
    void setPriorityS(string p);
    string getPriorityS();
    //get&set content functions
    void setContent(string c);
    string getContent();
    //get&set distination funcions
    void setDis(string d);
    string getDis(); 



    private:

    //priority
    int w_pl;
    string w_p;
    //package content
    string w_c;
    //destination
    string w_d;
    
    
};

#endif
