/**
*	@file :Test.cpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A method file for Test class, for test mode.
*/

#include "Test.h"
#include "BST.h"
#include "Pokemon.h"

ofstream Test::outfile;

Test::Test()
{   
    //okemon P2(std::string AN, int ID,std::string JN);
    
}

void Test::testWriteToFile(Pokemon& P2)
{
    outfile<<P2.getAN()<<","<<P2.getID()<<","<<P2.getJN()<<endl; 
}

void Test::testAdds(BST<Pokemon, std::string> bst)//testAdds method
{   
    Pokemon P2;
    std::cout<<"Give a new Pokemon name(US)"<< std::endl;
    std::string newUSname1="";
    std::cin>>newUSname1;

    std::string AN=newUSname1;
    std::cout<<"Give a new Pokemon name(JP)"<< std::endl;
    std::string newJPname1="";
    std::cin>>newJPname1;

    std::string JN=newJPname1;
    std::cout<<"Give a new Pokedex number"<< std::endl;
    int newPokedex1=0;
    std::cin>>newPokedex1;

    Pokemon newp1(newUSname1,newPokedex1,newJPname1);
    bst.Add(newp1);//add new item to copy tree
    std::cout<<"The new Pokemon has been added!"<< std::endl;
    bst.inorderTraverse(print);
}
void Test::testRemoves(BST<Pokemon, std::string> bst)//testRemoves method
{
    std::cout<<"Give a Pokemon name(US) which you want to remove"<< std::endl;
    std::string removename1="";
    std::cin>>removename1;
    if(bst.remove(removename1)==true)//remove item from copy tree
    {//writeToFile method
        std::cout<<removename1<<" has been removed"<< std::endl;
    }
    else
    {
        std::cout<<removename1<<" doesn't exist!"<< std::endl;
    }
    bst.inorderTraverse(print);
}
void Test::testWrite(BST<Pokemon, std::string> bst)//testWriteToFile method
{
    std::cout<<"Give a output file name:"<< std::endl;
    std::string O="";
    std::cin>>O;
    //std::ofstream of;
    outfile.open(O);
    //bst.inorderTraverse(&WriteToFile);
    bst.inorderTraverse(testWriteToFile);
    std::cout<<O<<" file has been created."<< std::endl;
    outfile.close();

}

void Test::print(Pokemon& P1)//print method
{
    cout<<P1.getAN()<<","<<P1.getID()<<","<<P1.getJN()<<endl; 
}
