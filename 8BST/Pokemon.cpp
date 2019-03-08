/**
*	@file :Pokemon.cpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief A method file for Pokemon class
*/

#include "Pokemon.h"
using namespace std;

//constructor
Pokemon::Pokemon()
{
    m_an = " ";
    m_id = 0;
    m_jn = " ";

}

//destructor
Pokemon::~Pokemon()
{
    
}

Pokemon::Pokemon(string AN, int ID, string JN)
{
    m_an=AN;
    m_id=ID;
    m_jn=JN;
    
}

//set & get functions
void Pokemon::setAN(string an)
{
    m_an=an;
}

string Pokemon::getAN() const
{
    return m_an;
}

void Pokemon::setID(const int id)
{
    m_id=id;   
}

int Pokemon::getID() const
{
    return m_id;
}

void Pokemon::setJN(const string jn)
{
    m_jn=jn;
}

string Pokemon::getJN() const
{
    return m_jn;
}