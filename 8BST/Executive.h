/**
*	@file :Executive.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for Executive class
*           Loading input data in to the BinarySearchTree.
*/

#include <istream>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "NotFoundException.h"
#include "BST.h"
#include "Pokemon.h"
#include "Test.h"

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;

class Executive
{
    static ofstream outputfile;
    
    public:
    
    static void WriteToFile(Pokemon& P1);//WriteToFile method
    //constructor
    Executive();
    //get choice from users function
    void Exec ();

    private:
    // ofstream outputfile;
    string outputname;
    //Pokemon P;
    
//outputfile.open(outputname);
// visit would be responsible to print entry data to out file stream.

// Instantiation in client(Executive class):
// BinarySearchTree<PokedexEntry, string> bst; // PokedexEntry->ItemType; string->KeyType
};
#endif 