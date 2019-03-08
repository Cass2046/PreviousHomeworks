/**
*	@file :Pokemon.h
*	@author :Lu Yin
*	@date :2017.03.28
*	@brief: A header file for Pokemon class,
*           Models a single data record read from the input file. 
*           Each record/object would be stored in a node of Binary Search Tree.
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pokemon
{
    public:
    //constructor
    Pokemon();
    Pokemon(string AN, int ID, string JN);

    //set & get functions
    void setAN(const string an);
    string getAN() const;

    void setID(const int id);
    int getID() const;
    
    void setJN(const string jn);
    string getJN() const;

     //destructor
    ~Pokemon();

    private:
   string m_an;
   int m_id;
   string m_jn;
};
#endif 
