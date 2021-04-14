#include "CJail.h"
#include <iostream>

CJail::CJail(int id, string name) : CSquare(id, name)
{
}

void CJail::LandOn(CPlayer* player1){

	if (player1->GetPosition() == 6)
	{
		cout << player1->GetName() + " lands on Jail" << endl;

		cout <<" "<< endl;

		cout << player1->GetName() + " is just visiting" << endl;

	}

}
