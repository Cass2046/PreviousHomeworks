/**
*	@file :StarWarsShip.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for StarWarsShip class
*/

#ifndef STARWARSHIP_H
#define STARWARSHIP_H

#include "SpaceShipInterface.h"
class StarWarsShip: public SpaceShipInterface
{
    public:
    StarWarsShip();
    StarWarsShip(std::string Pilot, int Attack, int Curh, int Maxh, int Shield, std::string l);
    // void setlastW(std::string l);
    std::string universe() const;
    std::string pilot_n() const;
    int attackPower() const;
    int maxHull() const;
    int currentHull() const;
    bool shield() const;
    void status()const;
    bool takeDamage(int amount);

    private:
    std::string W_u;
    std::string pilotN;
    int attackP;  //attack Power
    int curH; //current hull
    int maxH; //max hull
    int shieldS;
    std::string lastW;

};
#endif
