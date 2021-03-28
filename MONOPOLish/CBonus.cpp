#include "CBonus.h"
#include <iostream>


CBonus::CBonus(int id, string name) : CSquare(id, name) {}


void CBonus::LandOn(CPlayer* player1, int random)
{
	if (player1->GetPosition() == 3)
	{
		
		switch (random)
		{

		case 1:

			cout << "Find some money. Gain "  << 20  << endl;

			player1->AddMoney(20);

			break;

		case 2:

			cout << "Win a coding cpmpetition. Gain "  << 50 << endl;

			player1->AddMoney(50);


			break;

		case 3:

			cout << "Receive a rent rebate. Gain "  << 100 << endl;

			player1->AddMoney(100);

			break;

		case 4:

			cout << "Win the lottery. Gain "  << 150 << endl;

			player1->AddMoney(150);


			break;

		case 5:

			cout << "Receive a bequest. Gain " << 200 << endl;

			player1->AddMoney(200);


			break;

		case 6:

			cout << "It's your birthbay. Gain "  << 300 << endl;

			player1->AddMoney(300);

			break;

		}


	}



}
