//Andrii Bilyk

#include <iostream>
#include <string>

#include "CSquare.h"
#include "CPlayer.h"

#include <random>

using namespace std;


int Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

void Turn(CPlayer& player, CSquare board[]) {
  
    int rand = Random();
    
    cout << player.GetName() << " rolls " << rand << endl;

    player.AddPosition(rand);

    cout << player.GetName() << " lands " << board[player.GetPosition()].GetName() << endl;

    player.CheckIfGoIsPassed();

    cout << " " << endl;

}


int main()
{

    //board size
    const int boardSize = 26;

    //board array creation 
    CSquare board[boardSize] = { CSquare(2,"GO"), CSquare(1,"Red Road"),
    CSquare(1,"Red Street"), CSquare(4,"Bonus"), CSquare(1,"Grey Road"),
    CSquare(1,"Grey Street"), CSquare(6,"Jail"), CSquare(1,"Brown Road"),
    CSquare(1,"Brown Street"), CSquare(3,"Railway Station"), CSquare(1,"Orange Road"),
    CSquare(1,"Orange  Street"), CSquare(1,"Orange Way"), CSquare(8,"Free Parking"),
    CSquare(1,"Yellow Road"), CSquare(1,"Yellow Street"), CSquare(5,"Penalty"),
    CSquare(1,"Green Road"), CSquare(1,"Green Street"), CSquare(7,"Go to Jail"),
    CSquare(1,"Blue  Road"), CSquare(1,"Blue  Street"), CSquare(1,"Blue Way"),
    CSquare(3,"Bus Station"), CSquare(1,"Purple Road"), CSquare(1,"Purple Street"),
    };

    //players 
    CPlayer Dog = CPlayer("Dog",1500,0);
    CPlayer Car = CPlayer("Car", 1500,0);


    //srand(static_cast<unsigned int> (time(0))); random
    //or
    //srand(4); pre set



    cout << "----------------------" << endl;
    cout << "Welcome to Monopol-ish" << endl;
    cout << "----------------------" << endl;

    //sets the seed 4 Random() function
    srand(4);

    //simulates 20 turns
    for (int i = 0; i <= 20; i++)
    {
        cout << "Round: " << i << endl;


        Turn(Dog,board);
        
        Turn(Car, board);


        if (i == 20)
        {
            cout << Dog.GetName() << " has " << Dog.GetMoney() << endl;
            cout << Car.GetName() << " has " << Car.GetMoney() << endl;

            if (Dog.GetMoney() > Car.GetMoney())
            {
                cout << Dog.GetName() << " has " << endl;
            
            }
            else if(Dog.GetMoney() == Car.GetMoney())
            {
                cout <<"It's A draw !" << endl;
            }
            else
            {
                cout << Car.GetName() << " has " << endl;
            }
        
        
        
        }

    }


}

