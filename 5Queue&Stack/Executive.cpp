/**
*	@file :Executive.cpp
*	@author :Lu Yin
*	@date :2017.02.07
*	@brief Methods file for Exective class
*/
#include "Executive.h"
#include "Stack.h"
#include "Queue.h"
#include "StackInterface.h"
#include "QueueInterface.h"
#include "PreconditionViolationException.h"

#include <string>
#include <fstream>
#include <iostream>
#include <limits>
#include <cstddef>


Executive::Executive()
{

}

Executive::~Executive()
{
    
}

void Executive::run(char* n)
{
    int s=0;
    std::string c;
    //create a ticket Line list
    Queue<std::string>* ticket = new Queue<std::string>();
    //create a cinema seats list
    Stack<std::string>* seating = new Stack<std::string>();

    //read data from input file
    std::ifstream inp;
    inp.open(n);
  
    std::string name; //people in Line
    int num; //which one is ejected

    while(!inp.eof())
    {
        inp>>c;
        
        try
        { 
            //Person get a ticket 
            if(c=="TICKET")
            {
                inp>>name;
                //add a new customer to ticket line
                ticket->enqueue(name);
            }

            //People gett seated in the theater 
            else if (c=="SEATING")
            {
                //how many seats are available in the theater
                while (s<10)
                {
                    std::cout<<ticket->peekFront()<<" left the ticket line."<<std::endl;
                    seating->push(ticket->peekFront());//let people sit in theater
                    ticket->dequeue();//remove people from the waiting list
                    s++; //how many people in the theater
                }

            }

            // # number of people escorted out of theater
            else if(c=="EJECTION")
            {
                inp>>num;//which number is ejected
                //create a list of people will walk out from theater
                Stack<std::string>* eject = new Stack<std::string>();
                //amount people are walking out (add to eject list)
                for (int i=0; i<num; i++)
                {
                    eject->push(seating->peek());
                    seating->pop();
                }

                //remove the front
                std::cout<<eject->peek()<<" left the theater."<<std::endl;
                eject->pop();
                s--;

                //let other people back to seats
                for(int i=0; i<num; i++)
                {
                    seating->push(eject->peek());
                }
        
            }

            //The theater being emptied after the show
            else if (c=="CREDITS")
            {
                while (s!=0)
                {
                    std::cout<<seating->peek()<<" left the theater."<<std::endl;
                    seating->pop();
                    s--;
                }
            }

            // Print if theater is empty along with the current state of Stack(top) and Queue(front).
            else if (c=="STATUS")
            {
                std::cout<<"----------------------------- "<<std::endl;
                std::cout<<" Welcome to JayHawk Cineplex: "<<std::endl;
                // seating.peek();
                // std::cout<<ticket.peekFront()<<" is next in the ticket line."<<std::endl;
                if (seating->isEmpty()==true)
                {
                    std::cout<<" The theater is empty. "<<std::endl;
                    std::cout<<ticket->peekFront()<<" is next in the ticket line."<<std::endl;
                }
                else
                {
                    std::cout<<" The theater is not empty. "<<std::endl;
                    std::cout<<ticket->peekFront()<<" is next in the ticket line."<<std::endl;
                    std::cout<<seating->peek()<<" will be the first person to leave the theater."<<std::endl;
                }
                std::cout<<"----------------------------- "<<std::endl;
            }
        }
        catch (PreconditionViolationException e){std::cout<<e.what()<<std::endl;}             
    }
    inp.close();
}