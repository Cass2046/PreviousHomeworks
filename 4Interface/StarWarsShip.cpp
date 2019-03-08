/**
*	@file :StarWarsShip.cpp
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief Run methods for StarWarsShip class
*/
#include "StarWarsShip.h"

#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
//constructor
StarWarsShip::StarWarsShip()
{
    W_u="StarWars";
    pilotN="";
    attackP=0;  //attack Power
    curH=0; //current hull
    maxH=0; //max hull
    shieldS=0;
    lastW="";
}

StarWarsShip::StarWarsShip(std::string Pilot, int Attack, int Curh, int Maxh, int Shield, std::string l)
{
  pilotN=Pilot;
  attackP=Attack;
  curH=Curh;
  maxH=Maxh;
  shieldS=Shield;
  W_u="StarWars";
  lastW=l;
}
// void StarWarsShip::setlastW(std::string l)
// {
//     lastW=l;
// }

std::string StarWarsShip::universe() const
{
    return W_u;
}

std::string StarWarsShip::pilot_n() const
{
    return pilotN;
}

//the amount of damage a ship does with it attacks another ship
int StarWarsShip::attackPower() const
{
    return attackP;
}

int StarWarsShip::maxHull() const
{
    return maxH;
}

int StarWarsShip::currentHull() const
{
    return curH;
}

bool StarWarsShip::shield() const
{
  if(shieldS==0)
  {
    return false;
  }
  else
  {
    return true;
  }

}

//Each ship's pilot will yell something as they go down

void StarWarsShip::status() const
{
    if(curH!=0)
    {
        std::cout<<pilotN<<"'s ship has "<<curH<<" out of"<<maxH<<" remaining."<<std::endl;
    }
    else
    {
        std::cout<<"The final message from "<<pilotN<<": "<<lastW<<std::endl;
    }
}
bool StarWarsShip::takeDamage(int amount)
{
    curH=curH-amount;
    if (curH<=0) //the ship dies
    {
        return true;
    }
    else
    {
        return false;
    }
}
