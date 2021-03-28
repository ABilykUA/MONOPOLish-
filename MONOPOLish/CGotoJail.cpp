#include "CGotoJail.h"
#include <iostream>

CGotoJail::CGotoJail(int id, string name) : CSquare(id, name){
}


void CGotoJail::LandOn(CPlayer* player1)
{
	
	if (player1->GetPosition() == 19)
	{
		cout << player1->GetName() + " lands on Go to Jail" << endl;

		cout << " " << endl;

		cout << player1->GetName() + " goes to Jail" << endl;

		player1->SetPosition(6);

		cout << " " << endl;

		cout << player1->GetName() + " pays 50" << endl;

		player1->SubtractMoney(50);
	}

}




