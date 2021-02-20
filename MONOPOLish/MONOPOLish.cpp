//Andrii Bilyk

#include <iostream>
#include <string>


//heders
#include "CSquare.h"
#include "CPlayer.h"
#include "CRealEstate.h"

//from Random() 
#include <random>
#include <time.h>

using namespace std;


int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}


void WinCondition(int i, CPlayer* Dog, CPlayer* Car) {

    if (i == 20)
    {

        cout << " " << endl;
        cout << " " << endl;
        

        cout << Dog->GetName() << " has " << Dog->GetMoney() << endl;
        cout << Car->GetName() << " has " << Car->GetMoney() << endl;

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

void Turn(CPlayer* player1, CPlayer* player2, CRealEstate* board[]) {


  
    int rand = Random();
    
    cout << "---------------" << endl;

    cout << player1->GetName() << " rolls " << rand << endl;

    cout << "---------------" << endl;

    player1->AddPosition(rand);

    player1->CheckIfGoIsPassed();

    board[player1->GetPosition()]->LandOnRE(player1,player2);


    cout << " " << endl;

    cout << player1->GetName() << " lands " << board[player1->GetPosition()]->GetName() << endl;


    cout << " " << endl;

    cout << player1->GetName() << " has " << player1->GetMoney();
    
    cout << " " << endl;
    cout << " " << endl;


}


int main()
{

    //board size
    const int boardSize = 26;

    
    //board array creation 
    CRealEstate* board[boardSize] = { new CRealEstate(2,"GO"), new CRealEstate(1,"Red Road",60,5,0),
    new CRealEstate(1,"Red Street",80,10,0),new CRealEstate(4,"Bonus"),new CRealEstate(1,"Grey Road",100,15,1),
    new CRealEstate(1,"Grey Street",120,15,1),new CRealEstate(6,"Jail"),new CRealEstate(1,"Brown Road",140,20,2),
    new CRealEstate(1,"Brown Street",160,20,2),new CRealEstate(3,"Railway Station"),new CRealEstate(1,"Orange Road",180,25,3),
    new CRealEstate(1,"Orange  Street",180,25,3),new CRealEstate(1,"Orange Way",200,25,3),new CRealEstate(8,"Free Parking"),
    new CRealEstate(1,"Yellow Road",220,30,4),new CRealEstate(1,"Yellow Street",240,30,4),new CRealEstate(5,"Penalty"),
    new CRealEstate(1,"Green Road",260,35,5),new CRealEstate(1,"Green Street",280,35,5),new CRealEstate(7,"Go to Jail"),
    new CRealEstate(1,"Blue  Road",300,45,6),new CRealEstate(1,"Blue  Street",300,45,6),new CRealEstate(1,"Blue Way",320,45,6),
    new CRealEstate(3,"Bus Station"),new CRealEstate(1,"Purple Road",400,50,7),new CRealEstate(1,"Purple Street",420,5,7),
    };

    //players 
    CPlayer* Dog = new CPlayer("Dog",1500,0);
    CPlayer* Car = new CPlayer("Car", 1500,0);


    //srand(static_cast<unsigned int> (time(0))); random
    //or
    //srand(4); pre set



    cout << "----------------------" << endl;
    cout << "Welcome to Monopol-ish" << endl;
    cout << "----------------------" << endl;

    //sets the seed 4 Random() function
    srand(static_cast<unsigned int> (time(0)));

    //simulates 20 turns
    for (int i = 0; i <= 20; i++)
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


}

