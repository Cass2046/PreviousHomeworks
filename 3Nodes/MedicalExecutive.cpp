/**
*	@file :MedicalExecutive.cpp
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief Run methods for MedicalExecutive class
*/

#include "MedicalExecutive.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>

//constructor
MedicalExecutive::MedicalExecutive()
{

}
void MedicalExecutive::Exec(char* n)
{

  // list=new LinkedList<City>();
  // q_list=new LinkedList<City>();
  //read information from a given file
  std::ifstream inp;
  inp.open(n);
  std::string e_n;  //city name
  int e_p;  //population
  int e_l;  //infected level

  //transform e_p and e_l from int to string
  std::string e_pp;
  std::string e_ll;

  while(!inp.eof())   //keep reading
  {
    std::getline(inp,e_n,',');
    std::getline(inp,e_pp,',');
    std::getline(inp,e_ll);
    City C;
    e_l=stoi(e_ll);
    e_p=stoi(e_pp);
    C.setName(e_n);
    C.setPopulation(e_p);
    C.setLevel(e_l);
    //adding a new city in a empty list OR compare with
    //the list city's population and add to the last
    if(list.isEmpty() == true||list.getEntry(list.getlength()).getPopulation()>e_p)
    {
      list.addBack(C);
    }
    else
    {
      int length1=list.getlength();
      bool isinsert=false;
      for (int i=1; i<=length1; i++)
      {
        if(list.getEntry(i).getPopulation()<e_p && isinsert==false)
        {
          list.insert(i,C);
          isinsert=true;
        }
      }
    }
  }
    inp.close();
    std::cout<<list.getlength()<<std::endl;
    for (int i=1; i<=list.getlength(); i++)
      {
        std::cout<<list.getEntry(i).getName()<<std::endl;  //set the new level back to City
      }
    run();
}

//destructor
MedicalExecutive::~MedicalExecutive()
{
}

void MedicalExecutive::run()
{
  int option=0;
  while (option != 6)
  {
    std::cout<<"================================ "<<std::endl;
    std::cout<<"Make a selection: "<<std::endl;
    std::cout<<" "<<std::endl;
    std::cout<<"1) Increase infection level of all cities by 1 "<<std::endl;
    std::cout<<"2) Increase infection level of specific city by 1 "<<std::endl;
    std::cout<<"3) Print status of a specific city "<<std::endl;
    std::cout<<"4) Create quarantine log "<<std::endl;
    std::cout<<"5) Print all cities above an infection level "<<std::endl;
    std::cout<<"6) Exit "<<std::endl;
    std::cout<<"================================ "<<std::endl;
    std::cout<<"Choice:  "<<std::endl;

    std::cin>>option;

    if(option == 1)
    {
      //Increase infection level of all cities by 1
      for (int i=1; i<=list.getlength(); i++)
      {
        City C1 = list.getEntry(i);  //Create a new city and get the values in each city
        C1.inLevel();   //increase the infection level by 1
        list.setEntry(i, C1);  //set the new level back to City
      }
      std::cout<<"The infection level for all cities has been increased."<<std::endl;
      std::cout<<" "<<std::endl;
      levelAction();
    }

    else if(option == 2)  //Increase infection level of specific city by 1
    {
      std::string str="";
      std::cout<<"Which city do you want to infect?: "<<std::endl;
      std::cout << "City name: " << std::endl;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::getline(std::cin,str);

    bool isin=false;
    for (int i=1; i<=list.getlength(); i++)  //see whether the city exist in the list
    {
        if (list.getEntry(i).getName()==str)
        {
          City C1 = list.getEntry(i); //Create a city and get the values
          C1.inLevel();  //increase the infection level by 1
          list.setEntry(i, C1);  //set the new level back to City

          std::cout<<"----------------------- "<<std::endl;
          std::cout<<"Infection level for "<<" ' " <<str<<" ' "<<"increased by 1"<<std::endl;
          isin=true;
        }
      }
        if (isin==false)
       {
           for (int i=1; i<=list.getlength(); i++)
           {
             std::cout<<list.getEntry(i).getName()<<std::endl;  //set the new level back to City
            //  std::cout<<CI<<std::endl;  //set the new level back to City
           }
             std::cout<<"Sorry, "<<str<<" is not a city in the list. "<<std::endl;
       }
        levelAction();
  }

    else if(option == 3)  //Print status of a specific city
    {
      std::string str="";
      std::cout<<"Which city do you want to print the status?: "<<std::endl;
      std::cout << "City name: " << std::endl;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::getline(std::cin,str);
      std::cout<<str;

      bool isin=false;
      for (int i=1; i<=list.getlength(); i++)  //see whether the city exist in the list
      {
         if (list.getEntry(i).getName()==str)
         {
            std::cout<<"----------------------- "<<std::endl;
            std::cout<<"The status of  "<<str<<"is:  "<<std::endl;
            std::cout<<"Name:  "<<str<<std::endl;
            std::cout<<"Population:  "<<list.getEntry(i).getPopulation()<<std::endl;
            std::cout<<"infected level:  "<<list.getEntry(i).getLevel()<<std::endl;
            std::cout<<"----------------------- "<<std::endl;
            isin=true;
          }

       }
       if(isin==false)
       {
          std::cout<<"Sorry, "<<str<<"is not a city in the list. "<<std::endl;
       }
    }

    else if(option == 4)
    {
      //Create quarantine log
      std::string N;
      std::ofstream file;  //create a new file named file
      std::cout<<"Name the file (xxx.txt): "<<std::endl;
      std::cin>>N;
      file.open(N);
      if (q_list.isEmpty()!=true)
      {
        for (int i=1; i<=q_list.getlength(); i++)
        {
          file<<q_list.getEntry(i).getName()<<" , "<<q_list.getEntry(i).getPopulation()<<" , "<<q_list.getEntry(i).getLevel()<<std::endl;
        }
      }
      file.close();
      std::cout<<N<<" file is ready! "<<std::endl;
    }

    else if(option == 5)
    {
      int l;
      //Print all cities above an infection level
      std::cout<<"Please input the level to be aboved: "<<std::endl;
      std::cin>>l;
      for (int i=1; i<=list.getlength(); i++)
      {
        if(list.getEntry(i).getLevel()>l)
        {
          std::cout<<"Name: "<<list.getEntry(i).getName()<<std::endl;
          std::cout<<"Population: "<<list.getEntry(i).getPopulation()<<std::endl;
          std::cout<<"Infection Level: "<<list.getEntry(i).getLevel()<<std::endl;
        }
      }
    }

    else if(option == 6)
    {
      std::cout<<"Exiting... "<<std::endl;
      std::cout<<"Thank you! "<<std::endl;
    }

  }

}

void MedicalExecutive::levelAction()
{
  // int length2=list.getlength();
  for (int i=1; i<=list.getlength(); i++)
  {
    if(list.getEntry(i).getLevel() == 1)
    {
      City C = list.getEntry(i);
      //Decrease the population by 10% (round down)
      C.setPopulation(C.getPopulation()*0.9);

        //Remove this city from the list
         list.removeAt(i);

      //set the new level back to City
      // list.setEntry(i, C);

      //keeps the list sorted by population
      if(list.isEmpty() == true||list.getEntry(list.getlength()).getPopulation()>C.getPopulation())
      {
         list.addBack(C);
      }
      else
      {
        int length1=list.getlength();
        bool isinsert=false;
        for (int i=1; i<=length1; i++)
        {
          if(list.getEntry(i).getPopulation()<C.getPopulation()&& isinsert==false)
          {
            list.insert(i,C);
            isinsert=true;
          }
        }
      }
    }

      else if(list.getEntry(i).getLevel() == 2)
    {
      City C = list.getEntry(i);
      //Decrease the population by 20% (round down)
      C.setPopulation(C.getPopulation()*0.8);
      //Remove this city from the list
      list.removeAt(i);
      //set the new level back to City
      // list.setEntry(i, C);

      //keeps the list sorted by population
      if(list.isEmpty() == true||list.getEntry(list.getlength()).getPopulation()>C.getPopulation())
      {
        list.addBack(C);
      }
      else
      {
        int length1=list.getlength();
        bool isinsert=false;
        for (int i=1; i<=length1; i++)
        {
          if(list.getEntry(i).getPopulation()<C.getPopulation() && isinsert==false)
          {
            list.insert(i,C);
            isinsert=true;
          }
        }
      }

    }

    else if(list.getEntry(i).getLevel() == 3)
    {
      City C = list.getEntry(i);
      //Take 25% (round down) of the population
      C.setPopulation(C.getPopulation()*0.75);
      //Remove this city from the list
      list.removeAt(i);
      //set the new level back to City


      if(list.isEmpty() == true||list.getEntry(list.getlength()).getPopulation()>C.getPopulation())
      {
        list.addBack(C);
      }
      else
      {
        int length1=list.getlength();
        bool isinsert=false;
        for (int i=1; i<=length1; i++)
        {
          if(list.getEntry(i).getPopulation()<C.getPopulation() && isinsert==false)
          {

            list.insert(i,C);
            isinsert=true;
          }
        }
      }
    }

    else if (list.getEntry(i).getLevel() == 4)
    {
      City C = list.getEntry(i);
      //The city is removed from the infected list
      list.removeAt(i);

      //set the city with a new name
      C.setName("new "+C.getName());
      //set the city a new level to 0
      C.setLevel(0);

      //moved to the quarantined list (Decreasing order)
      if(q_list.isEmpty() == true||q_list.getEntry(q_list.getlength()).getPopulation()>C.getPopulation())
      {
        q_list.addBack(C);
      }
      else
      {
        int length1=q_list.getlength();
        bool isinsert=false;
        for (int i=1; i<=length1; i++)
        {
          if(q_list.getEntry(i).getPopulation()<C.getPopulation() && isinsert==false)
          {
            q_list.insert(i,C);
            isinsert=true;
          }
        }
      }

      //A message is printed to the screen
      std::cout<<"City "<<C.getName()<<" has been placed in quarantine"<<std::endl;
      std::cout<<" "<<std::endl;
      i--;
    }
  }
}
