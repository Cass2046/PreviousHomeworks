/**
*	@file :FightManager.cpp
*	@author :Lu Yin
*	@date :2017.02.16
*	@brief A header file for FightManager class
*/

#include "FightManager.h"
#include "LinkedList.h"
#include "StarTrekShip.h"
#include "StarWarsShip.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

FightManager::FightManager()
{

}

void FightManager::Exec(char* n)
{
  //read information from a given file
  std::ifstream inp;
  inp.open(n);

  //universe
  std::string universe;
  //
  //StarTrek
  //
    //captain name
    std::string t_captain;
    //attack power
    int t_attackp;
    //crew
    int t_crew;
    //max hull
    int t_maxH;
    //shield status
    int t_shield_status;
//
//StarWars
//
    //pilot name
    std::string w_pilot;
    //attack power
    int w_attackp;
    //max hull
    int w_maxH;
    //shield status
    int w_shieldS;
    //last word
    std::string  w_lastW;

    //transform int to string
    std::string tt_attackp;
    std::string ww_attackp;
    std::string tt_crew;
    std::string tt_maxH;
    std::string ww_maxH;
    std::string tt_shield_status;
    std::string ww_shieldS;

  while(!inp.eof())   //keep reading
  {
    std::getline(inp,universe,',');
    std::cout<<universe<<std::endl;
    if (universe=="StarTrek")
    {
        std::getline(inp,t_captain,',');
        std::getline(inp,tt_attackp,',');
        std::getline(inp,tt_crew,',');
        std::getline(inp,tt_maxH,',');
        std::getline(inp,tt_shield_status);

            //transform int to string
        t_attackp=stoi(tt_attackp);
        t_crew=stoi(tt_crew);
        t_maxH=stoi(tt_maxH);
        t_shield_status=stoi(tt_shield_status);

        SpaceShipInterface* ST=new StarTrekShip(t_captain, t_attackp, t_maxH, t_maxH, t_shield_status, t_crew);
        // ST->setCrew(t_crew);
        list.addBack(ST); //add to list

    }
    else
    {//StarWars
        std::getline(inp,w_pilot,',');
        std::getline(inp,ww_attackp,',');
        std::getline(inp,ww_maxH,',');
        std::getline(inp,ww_shieldS,',');
        std::getline(inp,w_lastW);

        //transform int to string
        w_attackp=stoi(ww_attackp);
        w_maxH=stoi(ww_maxH);
        w_shieldS=stoi(ww_shieldS);
        SpaceShipInterface* SW=new StarWarsShip(w_pilot, w_attackp, w_maxH, w_maxH, w_shieldS, w_lastW);
        // SW->setlastW(w_lastW);
        list.addBack(SW); //add to list

    }

  }
    inp.close();
    
    run();
}

//destructor
FightManager::~FightManager()
{
}

void FightManager::run()
{
    std::cout<<"================================ "<<std::endl;
    std::cout<<"New Fight! "<<std::endl;
    std::cout<<"================================ "<<std::endl;
    bool k=true;
    
  while(k==true)
  {
    bool left=true;
    for(int i=1; i<=list.getlength(); i++)
    {
      
      //Create a new spaceship and get the values in each universe
      if (list.getEntry(i)->universe()=="StarWars" && k==true)
      {
        bool at=false;
        for(int j=1; j<=list.getlength(); j++)
        {
          if (list.getEntry(j)->universe()=="StarTrek" && at==false) //find enemy
          {
            left=false;
            if (list.getEntry(j)->shield()==true)  //take shields
            {
               if((list.getEntry(j)->takeDamage(list.getEntry(i)->attackPower()*0.5))==true)
               {
                 list.getEntry(j)->status();
                //  list.getEntry(j)->destoryed();
                
                 list.removeAt(j);   //remove destoryed ship from the list
                 
               }
               else
               {
                 list.getEntry(j)->status();
               }
            }
            else  //no shields
            {
               if((list.getEntry(j)->takeDamage(list.getEntry(i)->attackPower()))==true)
               {
                 list.getEntry(j)->status();
                //  list.getEntry(j)->destoryed();
                 list.removeAt(j);  //remove destoryed ship from the list
                 
               }
               else
               {
                 list.getEntry(j)->status();
               }
            }
            at=true;
          }
        }
      }
      else if(list.getEntry(i)->universe()=="StarTrek" && k==true)
      {
        bool at=false;
        for(int j=1; j<=list.getlength(); j++)
        {
          if (list.getEntry(j)->universe()=="StarWars" && at==false)  //find enemy
          {
            left=false;
             if (list.getEntry(j)->shield()==true) //take shields
             {
               if((list.getEntry(j)->takeDamage(list.getEntry(i)->attackPower()*0.5))==true)
               {
                 list.getEntry(j)->status();
                 list.removeAt(j);  //remove destoryed ship from the list
              
               }
               else
               {
                 list.getEntry(j)->status();
               }
             }
            else  //without shield
            {
              if((list.getEntry(j)->takeDamage(list.getEntry(i)->attackPower()))==true)
              {
                 list.getEntry(j)->status();
                 list.removeAt(j);  //remove destoryed ship from the list
                
              }
              else
              {
                 list.getEntry(j)->status();
              }
            }
            at=true;
          }
        }
      //only one exsit in the list, the fight ends.
      // else    
    }
    if(left==true)
   {
     if(i==1)
     {
      if (list.getEntry(2)->shield()==true)  //take shields
      {
        if((list.getEntry(2)->takeDamage(list.getEntry(i)->attackPower()*0.5))==true)
        {
          list.getEntry(2)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(2);   //remove destoryed ship from the list    
        }
        else
        {
          list.getEntry(2)->status();
        }
      }
      else  //no shields
      {
        if((list.getEntry(2)->takeDamage(list.getEntry(i)->attackPower()))==true)
        {
          list.getEntry(2)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(2);  //remove destoryed ship from the list            
        }
        else
        {
          list.getEntry(2)->status();
        }
      }
     }
     else
     {
      if (list.getEntry(1)->shield()==true)  //take shields
      {
        if((list.getEntry(1)->takeDamage(list.getEntry(i)->attackPower()*0.5))==true)
        {
          list.getEntry(1)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(1);   //remove destoryed ship from the list    
        }
        else
        {
          list.getEntry(1)->status();
        }
      }
      else  //no shields
      {
        if((list.getEntry(1)->takeDamage(list.getEntry(i)->attackPower()))==true)
        {
          list.getEntry(1)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(1);  //remove destoryed ship from the list            
        }
        else
        {
          list.getEntry(1)->status();
        }
      }
     }
     for(int j=2; j<=list.getlength(); j++)
     {
      if (list.getEntry(j)->shield()==true)  //take shields
      {
        if((list.getEntry(j)->takeDamage(list.getEntry(i)->attackPower()*0.5))==true)
        {
          list.getEntry(j)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(j);   //remove destoryed ship from the list    
        }
        else
        {
          list.getEntry(j)->status();
        }
      }
      else  //no shields
      {
        if((list.getEntry(i+1)->takeDamage(list.getEntry(i)->attackPower()))==true)
        {
          list.getEntry(i+1)->status();
          //  list.getEntry(j)->destoryed();
          list.removeAt(j);  //remove destoryed ship from the list            
        }
        else
        {
          list.getEntry(j)->status();
        }
      }
    }
  }
}
  if(list.getlength()==1)
  {
        k=false;
  }
  }
  std::cout<<" The end!"<<std::endl;
}
