/**
*	@file :Executive.cpp
*	@author :Lu Yin
*	@date :2017.03.18
*	@brief: A method file for Executive class
*           Executing different operations on the data stored in BinarySearchTree, through user interface.
*/

// #include "BinaryNode.h"
// #include "BST.h"
#include "Pokemon.h"
#include "Executive.h"
#include "NotFoundException.h"
#include "BST.h"
#include "Test.h"
#include <string>
#include <fstream>
#include <iostream>

#include <limits>
#include <cstddef>
#include <sstream>

using namespace std;

// This line defines outputfile and completes it. 
//It pretty much looks like the declaration in .h file, 
//but without the static key-word, giving outputfile the scope of Executive class.
ofstream Executive::outputfile;

void Executive::WriteToFile(Pokemon& P1)
 {
     outputfile<<P1.getAN()<<","<<P1.getID()<<","<<P1.getJN()<<endl; 
 }

Executive::Executive()
{
    outputname="";
//outputfile.open(outputname);
}



//choice from the user
void Executive::Exec ()
{ 
        //create a new file
        string filename;
        cout<<"Enter your file name:"<<endl;
        //American name
        string AN;
        //ID#
        int ID;
        //Japanese name
        string JN;

        //create a new BST
        BST<Pokemon, string> bst;

        //read from file
        cin>>filename;
        ifstream inp;
        inp.open(filename);

        //transform int to string
        string s_id;

        while(!inp.eof())  //keep reading from the file till it ends
        {
            getline(inp, AN, ',');
            getline(inp, s_id, ',');
            getline(inp, JN);

            //transform int to string
            ID = stoi(s_id);

            //package in a Pokemon class
            Pokemon p(AN, ID, JN);

            //print out what's reading from the file
            cout<<AN<<" ,"<<ID<<", "<<JN<<endl;

            //add to bst
            if (AN!="" && s_id!="" && JN!="")
            {
                bst.Add(p);
            }
            
        }
        
        //close the file
        inp.close();
         
            //Search
            //Give the american version of a pokemon's name
            // and print it's Japanese name and Pokedex number
          int choose=0;
try
  {
    while(choose<=4)
    {
        cout<<" =Menus="<< endl;
        cout<<"1: Search"<< endl;
        cout<<"2: Save"<< endl;
        cout<<"3: Copy"<< endl;
        cout<<"4: Test"<<endl;
        cout<<"5: Quit"<< endl;
        cin>>choose;
        if(choose==1)
        {
            cout<<"Input a American version of a pokemon's name:"<< endl; 
            string n="";
            cin>>n;
            string out="";
            out = (bst.getEntry(n)).getJN();
            cout<<"Japanese name:"<<out<<", and Pokedex:"<<(bst.getEntry(n)).getID()<< endl;
        }
        else if(choose==2)
        {
            // static void WriteToFile(Pokemon P1)//WriteToFile method
            // {
            //     outputfile<<P1.getAN()<<","<<P1.getID()<<","<<P1.getJN()<<endl; 
            // }
            
            cout<<"Give a output file name:"<< endl;
            cin>>outputname;
            outputfile.open(outputname);
            cout<<"Choose a order"<< endl;
            cout<<"1. inorder"<< endl;
            cout<<"2. preorder"<< endl;
            cout<<"3. postorder"<< endl;
            int c1=0;
            cin>>c1;


            // Pokemon P;
            // WriteToFile(P);
            if(c1==1)
            {
                bst.inorderTraverse(&WriteToFile);//save original Dictionary in inorder
            }
            else if(c1==2)
            {
                bst.preorderTraverse(&WriteToFile);//save original Dictionary in preorder
            }
            else if(c1==3)
            {
                bst.postorderTraverse(&WriteToFile);//save original Dictionary in postorder
            }
            cout<<outputname<<" file has been created."<< endl;
            outputfile.close();
        }
        else if(choose==3)
        {
            BST<Pokemon, string> copyB(bst);
            cout<<"CopyTree has been created. You can start your edit to the copyTree"<< endl;
            int c3=0;
            while(c3<5)
            {        
                cout<<"1: Add"<< endl;
                cout<<"2: Remove"<< endl;
                cout<<"3: Save"<< endl;
                cout<<"4: Test"<< endl; 
                cout<<"5: return"<< endl;  
                cin>>c3;
                if(c3==1)
                {
                    cout<<"Give a new Pokemon name(US)"<< endl;
                    string newUSname="";
                    cin>>newUSname;
                    cout<<"Give a new Pokemon name(JP)"<< endl;
                    string newJPname="";
                    cin>>newJPname;
                    cout<<"Give a new Pokedex number"<<endl;
                    int newPokedex=0;
                    cin>>newPokedex;
                    Pokemon newp(newUSname,newPokedex,newJPname);
                    copyB.Add(newp);//add new item to copy tree
                    cout<<"The new Pokemon has been added!"<<endl;
                }
                else if(c3==2)
                {
                    cout<<"Give a Pokemon name(US) which you want to remove"<< endl;
                    string removename="";
                    cin>>removename;
                    if(copyB.remove(removename)==true)//remove item from copy tree
                    {
                        cout<<removename<<" has been removed"<< endl;
                    }
                    else
                    {
                        cout<<removename<<" doesn't exist!"<< endl;
                    }
                }
                else if(c3==3)
                {
                     cout<<"Give a output file name:"<< endl;
                     cin>>outputname;
                     outputfile.open(outputname);
                     cout<<"Which dictionary you want to save?"<< endl;
                     cout<<"1. Original Tree"<< endl;
                     cout<<"2. Copy Tree"<< endl;
                     int c=0;
                     cin>>c;
                     cout<<"Choose a order"<< endl;
                     cout<<"1. inorder"<< endl;
                     cout<<"2. preorder"<< endl;
                     cout<<"3. postorder"<< endl;
                     int co=0;
                     cin>>co;
                     if(c==1)
                     {
                        // Pokemon P;
                        // WriteToFile(P);
                        if(co==1)
                        {
                            bst.inorderTraverse(WriteToFile);//save original Dictionary in inorder
                        }
                        else if(co==2)
                        {
                            bst.preorderTraverse(WriteToFile);//save original Dictionary in preorder
                        }
                        else if(co==3)
                        {
                            bst.postorderTraverse(WriteToFile);//save original Dictionary in postorder
                        }
                        cout<<outputname<<" file has been created."<< endl;
                        
                     }
                     else if(c==2)
                     {
                        // Pokemon P;
                        // WriteToFile(P);
                        if(co==1)
                        {
                            copyB.inorderTraverse(WriteToFile);//save copy tree in inorder
                        }
                        else if(co==2)
                        {
                            copyB.preorderTraverse(WriteToFile);//save copy tree in preorder
                        }
                        else if(co==3)
                        {
                            copyB.postorderTraverse(WriteToFile);//save copy tree in postorder
                        }
                        cout<<outputname<<" file has been created."<< endl;
                     }
                     else
                     {
                         cout<<"Input a wrong number"<< endl;
                     }

                     outputfile.close();
                }
            }

        }
        else if(choose==4)
        {
                    Test T;
                    cout<<"Which test you want to run?"<<endl;
                    cout<<"1. testAdds"<<endl;
                    cout<<"2. testRemoves"<<endl;
                    cout<<"3. testWriteToFile"<<endl;
                    int c4=0;
                    cin>>c4;
                    if(c4==1)
                    {
                        T.testAdds(bst);//call testAdds method
                    }
                    else if(c4==2)
                    {
                        T.testRemoves(bst);//call testRemoves method
                    }
                    else if(c4==3)
                    {
                        T.testWrite(bst);//call testWriteToFile method
                    }
        }   

    }
  }
    catch (NotFoundException e) {cout<<e.what()<<endl;}
    cout<<"Thanks for playing!"<<endl;
    cout<<"Bye."<<endl;
}
