/**
*	@file :FightManager.h
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for templated FightManager class
*/

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
//#include "Node.h"
#include "LinkedList.h"
#include "StarTrekShip.h"
#include "StarWarsShip.h"
#include "SpaceShipInterface.h"


class FightManager
{
    public:
    //constructor
    FightManager();
    void Exec(char*);
    ~FightManager();
    void run();


    private:
    LinkedList<SpaceShipInterface*> list;
};
#endif
