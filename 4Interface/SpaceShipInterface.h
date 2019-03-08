/**
*	@file :SpaceShipInterface.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for SpaceShipInterface class
*/

#ifndef SPACESHIPINTERFACE_H
#define SPACESHIPINTERFACE_H
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>


//#include "StarWarsShip.h"
//#include "StarTrekShip.h"

class SpaceShipInterface
{
    public:
    // SpaceShipInterface();
    // SpaceShipInterface(std::string Captain, int Attack, int Curh, int Maxh, int Shield );


    ~SpaceShipInterface() {}
    //Returns the attack power of a ship
     virtual int attackPower() const=0;



    //Returns the amount of damage the hull can still sustain.
    //Once a hull value reaches 0, the ship is destroyed
     virtual int currentHull() const=0;
    //Return the value the hull started the fight with
     virtual int maxHull() const=0;
     virtual bool takeDamage(int amount)=0;
     virtual bool shield() const=0;
     virtual std::string universe() const=0;
     virtual void status() const=0;

};

#endif
