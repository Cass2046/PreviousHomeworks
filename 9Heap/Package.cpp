/**
*	@file :Package.hpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A method file for Package class
*           
*/

//#include "Package.h"
//#include "HeapInterface.h"
#include "Package.h"
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <cstddef>
using namespace std;

//constructor
Package::Package()
{
    //priority
    w_pl=0;
    w_p="";
    //package content
    w_c="";
    //destination
    w_d="";
 }
Package::Package(int pl, string p, string c, string d)
{
    w_pl=pl;
    w_p=p;
    w_c=c;
    w_d=d;
}

//get&set Priority functions
void Package::setPriority(int pl)
{
    w_pl=pl;
}

int Package::getPriority()
{
    return w_pl;
}

void Package::setPriorityS(string p)
{
    w_p=p;
}

string Package::getPriorityS()
{
    return w_p;
}
    
//get&set content functions
void Package::setContent(string c)
{
    w_c=c;
}

string Package::getContent()
{
    return w_c;
}
    
//get&set distination funcions
void Package::setDis(string d)
{
    w_d=d;
}

string Package::getDis()
{
    return w_d;
}




