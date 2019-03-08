/**
*	@file :City.h
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A header file for templated City class
*/
#ifndef City_H
#define City_H
#include <string>

class City
{
  public:
  //constructor & destructor
  City();
  ~City();
   //set name
    void setName(std::string name);

    //set population
    void setPopulation(int population);

    //set infection level
    void setLevel(int level);

    //return city name
    std::string getName();

    //return city population
    int getPopulation();

    //return infection level
    int getLevel();

    //increase the infection level by 1
    void inLevel();


  private:
  std::string c_n; //City name
  int c_p; //City population
  int c_l; //City infection level
};
#endif
