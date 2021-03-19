#include "CBonus.h"
#include <iostream>

const char POUND = 156;

CBonus::CBonus(int id, string name) : CSquare(id, name) {}


void CBonus::LandOn(CPlayer* player1, int random)
{
	if (player1->GetPosition() == 3)
	{
		
		switch (random)
		{

		case 1:

			cout << "Find some money. Gain " <<POUND << 20  << endl;

			player1->AddMoney(20);

			break;

		case 2:

			cout << "Win a coding cpmpetition. Gain " << POUND << 50 << endl;

			player1->AddMoney(50);


			break;

		case 3:

			cout << "Receive a rent rebate. Gain " << POUND << 100 << endl;

			player1->AddMoney(100);

			break;

		case 4:

			cout << "Win the lottery. Gain " << POUND << 150 << endl;

			player1->AddMoney(150);


			break;

		case 5:

			cout << "Receive a bequest. Gain " << POUND << 200 << endl;

			player1->AddMoney(200);


			break;

		case 6:

			cout << "It's your birthbay. Gain " << POUND << 300 << endl;

			player1->AddMoney(300);

			break;

		}


		cout << " " << endl;

		cout << player1->GetName() << " has " << player1->GetMoney() << endl;

	}

}
