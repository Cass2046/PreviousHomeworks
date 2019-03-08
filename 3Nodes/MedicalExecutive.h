/**
*	@file :MedicalExecutive.h
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief A header file for templated MedicalExecutive class
*/

#ifndef MEDICALEXECUTIVE_H
#define MEDICALEXECUTIVE_H

#include "Node.h"
#include "City.h"
#include "LinkedList.h"

class MedicalExecutive
{
public:
  //constructor
  MedicalExecutive();
  void Exec(char* n);
  //destructor
  ~MedicalExecutive();
  //run method
  void run();
  //Infection level required actions
  void levelAction();


private:
  LinkedList<City> list;
  LinkedList<City> q_list;

};
#endif
