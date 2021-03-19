//Andrii Bilyk

//memory 
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

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

const char POUND = 156;

int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}


void WinCondition(int i, CPlayer* Dog, CPlayer* Car) {

    if (i == 20)
    {

        cout << " " << endl;
        cout << " " << endl;
        

        cout << Dog->GetName() << " has "<< POUND << Dog->GetMoney() << endl;
        cout << Car->GetName() << " has " << POUND <<Car->GetMoney() << endl;

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





    }
}

void Turn(CPlayer* player1, CPlayer* player2, vector<CSquare*>& board) {


  
    int rand = Random();
    
    cout << "---------------" << endl;

    cout << player1->GetName() << " rolls " << rand << endl;

    cout << "---------------" << endl;



    player1->AddPosition(rand);

    player1->CheckIfGoIsPassed();


    cout << " " << endl;


    cout << player1->GetName() << " lands " << board.at(player1->GetPosition())->GetName() << endl;

    //Realestare
    board.at(player1->GetPosition())->LandOn(player1, player2);
    
    //BonusORPenalty
    board.at(player1->GetPosition())->LandOn(player1, Random());

    //station
    board.at(player1->GetPosition())->LandOn(player1);


    cout << " " << endl;



    cout << player1->GetName() << " has " << POUND  << player1->GetMoney();
    


    cout << " " << endl;
    cout << " " << endl;


}


void GetArryData(vector<CSquare*>& Test) {

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


                    Test.push_back(new CRealEstate(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2), stoi(VecDATA.at(3)), stoi(VecDATA.at(4)), stoi(VecDATA.at(5))));

                    break;
              


                case 2:


                    Test.push_back(new CSquare(stoi(VecDATA.at(0)), VecDATA.at(1)));

                    break;

                case 3:  
                    
                  
                    Test.push_back(new CStation(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2), 200, 10));
                    break;

                case 4:

                   
                    Test.push_back(new CBonus(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;


                case 5:

                    
                    Test.push_back(new CPenalty(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;
               
                

                case 6:


                    Test.push_back(new CJail(stoi(VecDATA.at(0)), VecDATA.at(1)));
                    break;



                case 7:

                  
                    Test.push_back(new CGotoJail(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2) + " " + VecDATA.at(3)));
                    break;

               
                case 8:

                   
                    Test.push_back(new CFreeParking(stoi(VecDATA.at(0)), VecDATA.at(1) + " " + VecDATA.at(2)));
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

int main()
{
    _crtBreakAlloc = -1;

    
    //board size
    const int boardSize = 26;
    
    //board array
    vector<CSquare*> board;
    

    //players 
    CPlayer* Dog = new CPlayer("Dog",1500,0);
    CPlayer* Car = new CPlayer("Car", 1500,0);


    //get data from file
    GetArryData(board);



    //srand(static_cast<unsigned int> (time(0))); random
    //or
    //srand(4); pre set


    cout << "----------------------" << endl;
    cout << "Welcome to Monopol-ish" << endl;
    cout << "----------------------" << endl;

    //sets the seed 5 Random() function
     srand(static_cast<unsigned int> (time(0)));



    //simulates 20 turns
    for (int i = 1; i <= 20; i++)
    {
        
        cout << "==========" << endl;
        cout << "Round: " << i << endl;
        cout << "==========" << endl;

        cout << " " << endl;
     

        //Dogs turn
        Turn(Dog, Car, board);

        //Cars turn
        Turn(Car, Dog, board);


        //checks for win condition
        WinCondition(i, Dog, Car);
       

    }

  

    delete Dog;
    delete Car;
    for (int i = 0; i < board.size(); i++)
    {
    
        delete board[i];
    
    }

    _CrtDumpMemoryLeaks();
}

