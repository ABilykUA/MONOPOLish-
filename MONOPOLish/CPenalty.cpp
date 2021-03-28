#include "CPenalty.h"
#include <iostream>


CPenalty::CPenalty(int id, string name) : CSquare(id, name) {}


void CPenalty::LandOn(CPlayer* player1, int random)
{

	if (player1->GetPosition() == 16)
	{

		switch(random)
		{
		
		case 1:

			cout << "Buy a coffee in Starbucks. Lose " << 20  << endl;

			player1->SubtractMoney(10);

			break;
		
		case 2:

			cout << "Pay your broadband bill. Lose " << 50  << endl;

			player1->SubtractMoney(50);


			break;

		case 3:

			cout << "Visit the SU shop for food. Lose "  << 100  << endl;

			player1->SubtractMoney(100);

			break;

		case 4:

			cout << "Buy an assigment solution. Lose " << 150  << endl;

			player1->SubtractMoney(150);


			break;

		case 5:

			cout << "Go for a romantic meal. Lose " << 200  << endl;

			player1->SubtractMoney(200);


			break;

		case 6:


			cout << "Pay some university fees. Lose " << 300  << endl;

			player1->SubtractMoney(300);

			break;

		}


	


	}


}
