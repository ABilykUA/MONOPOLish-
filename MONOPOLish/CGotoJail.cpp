#include "CGotoJail.h"
#include <iostream>

CGotoJail::CGotoJail(int id, string name) : CSquare(id, name){
}


void CGotoJail::LandOn(CPlayer* player)
{
	
	if (player->GetPosition() == 19)
	{
		cout << player->GetName() + " lands on Go to Jail" << endl;

		cout << " " << endl;

		cout << player->GetName() + " goes to Jail" << endl;

		player->SetPosition(6);

		cout << " " << endl;

		cout << player->GetName() + " pays 50" << endl;

		player->SubtractMoney(50);
	}

}




