/**
*	@file :City.cpp
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief Methods for City class
*/
#include "City.h"

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>

City::City()  //constructor
{
  c_n = "";
  c_p = 0;
  c_l = 0;
}

City::~City()  //destructor
{

}

void City::setName(std::string name)   //set name
{
  c_n = name;
}

void City::setPopulation(int population)   //set population
{
  c_p = population;
}

void City::setLevel(int level)   //set infection level
{
  c_l = level;
}

std::string City::getName()   //return city name
{
  return c_n;
}

int City::getPopulation()   //return city population
{
  return c_p;
}

int City::getLevel()   //return infection level
{
  return c_l;
}

void City::inLevel()  //increase the infection level by 1
{
  c_l=c_l+1;
}