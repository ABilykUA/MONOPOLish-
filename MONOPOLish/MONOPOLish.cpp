//Andrii Bilyk

//memory 
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <memory.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//heders
#include "CSquare.h"
#include "CPlayer.h"
#include "CRealEstate.h"
#include "CJail.h"
#include "CGotoJail.h"
#include "CFreeParking.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"

//from Random() 
#include <random>
#include <time.h>

using namespace std;


int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}


void WinCondition(int i, shared_ptr<CPlayer>Dog  , shared_ptr<CPlayer> Car) {

    if (i == 20)
    {

        cout << " " << endl;
        cout << " " << endl;
        
        cout << "===================" << endl;
        
        if (Dog->GetMoney() > Car->GetMoney())
        {
            cout << Dog->GetName() << " won !" << endl;

        }
        else if (Dog->GetMoney() == Car->GetMoney())
        {
            cout << "It's A draw !" << endl;
        }
        else
        {
            cout << Car->GetName() << " won !" << endl;
        }
        cout << Dog->GetName() << " has " << Dog->GetMoney() << endl;
        cout << Car->GetName() << " has " << Car->GetMoney() << endl;

        cout << "=================== " << endl;



    }
}

void Turn(shared_ptr<CPlayer> player1, shared_ptr<CPlayer> player2, vector<shared_ptr<CSquare>>& board) {

  
    int rand = Random();
    
    cout << "---------------" << endl;

    cout << player1->GetName() << " rolls: " << rand << endl;

    cout << "---------------" << endl;



    player1->AddPosition(rand);

    player1->CheckIfGoIsPassed();


    cout << " " << endl;


    cout << player1->GetName() << " lands " << board.at(player1->GetPosition())->GetName() << endl;

  
    board.at(player1->GetPosition())->LandOnSquare(player1.get(), player2.get(), Random());


    cout << " " << endl;



    cout << player1->GetName() << " has "<< player1->GetMoney();
    


    cout << " " << endl;
    cout << " " << endl;


}

void GetArryData(vector<shared_ptr<CSquare>>& board) {

    //storing a file's line in a string 
    string DATA;
    
    //vector to split and store the strings value
    vector<string> VecDATA(6);

    //file name
    ifstream file;

    file.open("Monopoly.txt");

    if(file.is_open()){
    

        while (!file.eof())
        {

            //saves file's line in a string 
            getline(file, DATA, '\n');

            //counter for words in string, to split
            int i = 0;
           
            //takes DATA string and splits it into a usebe vector 
            stringstream ssin(DATA);
            while (ssin.good() && i < 6) {
            
                ssin >> VecDATA[i];
  
                ++i;
             
            }
               // sorts data by comparing ID and creates a new class 
                switch (stoi(VecDATA.at(0)))
                {


                case 1:
                   
                    board.push_back(make_shared<CRealEstate>(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2), stoi(VecDATA.at(3)), stoi(VecDATA.at(4)), stoi(VecDATA.at(5))));

                    break;
         


                case 2:


                    board.push_back(make_shared<CSquare>(stoi(VecDATA.at(0)), VecDATA.at(1)));

                    break;

                case 3:  
                    
                  
                    board.push_back(make_shared<CStation>(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2), 200, 10));
                    break;

                case 4:

                   
                    board.push_back(make_shared<CBonus>(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;


                case 5:

                    
                    board.push_back(make_shared<CPenalty>(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;
               
                

                case 6:


                    board.push_back(make_shared<CJail>(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;



                case 7:

                  
                    board.push_back(make_shared<CGotoJail>(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2) + " " + VecDATA.at(3)));
                    break;

               
                case 8:

                   
                    board.push_back(make_shared<CFreeParking>(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2)));
                    break;



               
                    
                }
                
         
              
            

        }
    
    }
    else
    {

        cout << "Error no file found";

    }



    file.close();


}

void WraperForMemoryDeallocation() {


    _crtBreakAlloc = -1;

    //board array
    vector<shared_ptr<CSquare>> board;

    shared_ptr<CPlayer>Dog = make_shared<CPlayer>("Dog", 1500, 0);
    shared_ptr<CPlayer>Car = make_shared<CPlayer>("Car", 1500, 0);

    //players 
    
     //get data from file
    GetArryData(board);


    cout << "----------------------" << endl;
    cout << "Welcome to Monopol-ish" << endl;
    cout << "----------------------" << endl;

    
    //simulates 20 turns
     
    srand(5);
    for (int i = 1; i <= 20; i++)
    {
        
        cout << "==========" << endl;
        cout << "Round: " << i << endl;
        cout << "==========" << endl;

        cout << " " << endl;
     

        //Dogs turn
        Turn(Dog,Car, board);

        //Cars turn
        Turn(Car,Dog, board);


        //checks for win condition
        WinCondition(i,Dog,Car);
       

    }

  
}

int main()
{
 
    WraperForMemoryDeallocation();

    _CrtDumpMemoryLeaks();
}

