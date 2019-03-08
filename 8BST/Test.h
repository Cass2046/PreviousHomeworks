/**
*	@file :Test.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for Test class, for test mode.        
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "BST.h"
#include "Pokemon.h"

#ifndef TEST_H
#define TEST_H


class Test
{
    static ofstream outfile;
    public:
    //constructor
    Test();
    static void testWriteToFile(Pokemon& P2);//WriteToFile method
    void testAdds(BST<Pokemon, std::string> bst);//testAdds method
    void testRemoves(BST<Pokemon, std::string> bst);//testRemoves method
    static void print(Pokemon& P1);//print method
    void testWrite(BST<Pokemon, std::string> bst);
    
    
    //static void testWriteToFile(Pokemon& bst);

    private:
    
    
};
#endif 
